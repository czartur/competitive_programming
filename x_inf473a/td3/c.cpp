#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int N =1e5+5;

void solve(){
  int n; cin >> n;
  vector<ll> w(n);
  for(auto &x : w) cin >> x; 

  vector<vector<ll>> dp(n*1000+1, vector<ll>(n));
  for(int val=0; val<=n*1000; ++val){
    dp[0][0] = 1;
    dp[val][0] = (w[0]==val);
    for(int i=1; i<n; ++i){
      dp[0][i] = 1;
      // nao pega
      dp[val][i] = dp[val][i-1];
      // pega
      if(val - w[i] >= 0) dp[val][i] += dp[val-w[i]][i-1];
    }
  }

  ll ans = 0;
  for(int val=200; val<=n*1000; ++val) ans += dp[val][n-1]*val;
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
