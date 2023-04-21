#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, W; cin >> N >> W;

  vector<vector<pair<ll, ll>>> item(W+1);
  for(int w=W; w>=0; --w){
    int k; cin >> k; 
    item[w].resize(k);
    for(auto &val : item[w]) cin >> val.first;
    for(auto &val : item[w]) cin >> val.second;
    // sort(item[w].begin(), item[w].end());
  }

  vector<vector<ll>> dp(W+1, vector<ll>(N+1));
  ll first_price = LINF;
  for(int w=0; w<=W; ++w){
    // n seats available this week
    for(ll n=0; n<=N; ++n){
      for(auto [p, s] : item[w]){
        ll profit = min(n,s)*p + ((w>0) ? dp[w-1][n-min(n,s)] : 0);
        if(dp[w][n] < profit){
          dp[w][n] = profit;
          first_price = p;
        }
        else if(dp[w][n] == profit) first_price = min(first_price, p);
      }
    }
  } 
  cout << dp[W][N] << endl;
  cout << first_price << endl;
}