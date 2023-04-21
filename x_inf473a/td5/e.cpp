#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5+5;

vector<int> recovery(int i, int w, vector<vector<ll>> &dp, vector<pair<ll,ll>> &item){
  assert(w >=0);

  if(i == 0){
    if(w >= item[0].second) return vector<int>{0};
    return vector<int>();
  }
  if(dp[i][w] == dp[i-1][w]) return recovery(i-1, w, dp, item);

  vector<int> idx = recovery(i-1, w-item[i].second, dp, item);
  idx.push_back(i);
  return idx;
}
int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, n;
  while(cin >> c >> n){
    vector<pair<ll,ll>> item(n);
    for(auto& val : item) cin >> val.first >> val.second;

    vector<vector<ll>> dp(n, vector<ll>(c+1));
    
    for(int i=1; i<n; ++i){
      auto [v, p] = item[i];
      for(int w=0; w<=c; ++w){
        dp[0][w] = (w >= item[0].second)*item[0].first;
        dp[i][w] = dp[i-1][w];
        if(w-p >= 0) dp[i][w] = max(dp[i][w], v + dp[i-1][w-p]);
      }
    }

    auto ans = recovery(n-1, c, dp, item);
    cout << ans.size() << endl;
    for(auto val : ans) cout << val << " ";
    cout << endl;
    
  }
}
