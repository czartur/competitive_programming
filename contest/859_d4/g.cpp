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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =5e3+3;

void solve(){
  int n; cin >> n;
  vector<int> c(n);
  for(auto &val : c) cin >> val;
  sort(c.begin(), c.end());

  vector<vector<bool>> dp(n, vector<bool>(N));
  dp[0][c[0]] = dp[0][0] = 1;
  for(int i=1; i<n; i++){
    dp[i][0]=1;
    for(int v=1; v<N; v++){
      if(v-c[i] >= 0) dp[i][v]=dp[i-1][v]||dp[i-1][v-c[i]];
      else dp[i][v] = dp[i-1][v];
    }
  }
  bool ok = c[0] == 1;
  for(int i=1; i<n; i++){
    ok &= dp[i-1][c[i]];
  }
  cout << (ok ? "yes" : "no") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
