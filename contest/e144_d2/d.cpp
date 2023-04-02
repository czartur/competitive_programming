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
const int N =2e5+5, K=21;

ll dp[N][K][3],a[N];
ll n, k, x; 

ll rec(int i, int j, int t){
  if(t<0 || j<0 || j>i) return -LINF;
  if(i == 0) return 0;
  if(~dp[i][j][t]) return dp[i][j][t];

  ll ans = 0;
  for(int jj=j-1; jj<=j; jj++){
    for(int tt=t-1; tt<=t; tt++){
      ans = max(ans, rec(i-1, jj, tt) + (t==1)*((jj==j-1)*2*x + a[i]));
    }
  }
  return dp[i][j][t] = ans;
}

void solve(){
  cin >> n >> k >> x;
  for(int i=1; i<=n; i++) cin >> a[i], a[i]-=x;
  
  for(int i=1; i<=n; i++)
    for(int j=0; j<=k; j++)
      for(int t=0; t<3; t++)
        dp[i][j][t] = -1;

  cout << max(rec(n,k,2), rec(n,k,1)) << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
