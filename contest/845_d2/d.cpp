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

int dfs(int u, int pai, vector<int> adj[], int d[] ){
  d[u] = 0;
  for(auto v: adj[u]){
    if(v != pai) d[u] = max(1+dfs(v, u, adj, d), d[u]);
  }
  return d[u];
}

ll fexp(ll b, ll e){
  ll ans = 1;
  while(e){
    if(e&1) ans = (ans*b)%mod;
    b=(b*b)%mod;
    e/=2;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> adj[n];
    int d[n];
    
    for(int i=0; i<n-1; i++){
      int u, v; cin >> u >> v;
      u--; v--;
      adj[u].pb(v); adj[v].pb(u);
    }

    d[0] = dfs(0, 0, adj, d);
    ll ans = 0;

    for(int i=0; i<n; i++)
      ans = (ans + d[i]+1)%mod;

    cout << (fexp(2, n-1)*ans)%mod << endl;
  }
}
