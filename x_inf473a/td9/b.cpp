#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =2e6+1;

int greed(int target, vector<int>&coin){
  int pos = coin.size()-1;
  int ans = 0;
  while(pos >= 0){
    // db(target);
    if(target >= coin[pos]){
      ans += target/coin[pos];
      target %= coin[pos];
    }
    // db(ans);
    --pos;
  }
  return ans;
}

int memo[N];
int dp(int target, vector<int>&coin){
  if(target == 0) return 0;
  if(target < 0) return INF;  
  if(memo[target]) return memo[target];

  int ans = INF;
  for(auto c : coin){
    ans = min(ans, dp(target-c, coin)+1);
  }
  return memo[target] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> coin(n);
  for(auto& val : coin) cin >> val;

  bool canonical = 1;
  for(int i = coin[n-2]; i <= coin[n-2]+coin[n-1]; ++i){
    if(greed(i, coin) != dp(i, coin)) canonical = 0;
    // db(i);
    // db(greed(i, coin));
    // db(dp(i, coin));
  }
  cout << (canonical ? "canonical" : "non-canonical") << endl;
}
