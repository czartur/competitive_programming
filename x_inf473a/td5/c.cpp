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

vector<vector<ll>> solve(){
  vector<vector<ll>> dp(101, vector<ll>(100));
  dp[1][0] = 1;
  for(int n=2; n<=100; ++n){
    dp[n][0] = 1;
    for(ll v=1; v<=n-1; ++v){
      dp[n][v] += ((n-v)*dp[n-1][v-1])%MOD;
      dp[n][v] += ((v+1)*dp[n-1][v])%MOD;
      dp[n][v]%=MOD;
    }
  }
  return dp;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto dp = solve();
  int p; cin >> p;
  while(p--){
    int k, n, v; cin >> k >> n >> v;
    cout << k << " " << dp[n][v] << endl;
  }
}
