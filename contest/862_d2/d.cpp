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
const int N =2e5+5;
 

class DSU{
  vector<int> par;
  vector<int> weight;

  public:
  int size;
  
  DSU(int n) : size{n}{
    par.resize(n);
    weight.resize(n);
    iota(par.begin(), par.end(), 0); // singletons
  }

  int find(int a){
    if(par[a]==a) return a;
    return par[a]=find(par[a]);
  }

  void join(int a, int b){
    a=find(a), b=find(b);
    if(a != b) size--;
    if(weight[a]<weight[b]) swap(a,b);
    par[a]=b;
    weight[b]+=weight[a];
  }
};

void dfs(int u, int altura, int &last, vector<vector<int>> &adj, vector<pair<int,int>> &h){
  h[u] = {altura, u};
  if(altura > h[last].first) last = u;
  for(auto &v : adj[u]) if(h[v].first == -1) dfs(v, 1+altura, last, adj, h);
}

void solve(){
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i=0; i<n-1; ++i){
    int u, v; cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // find longest path
  int last=0, start, end;
  vector<pair<int,int>> l(n), r(n);
  
  // find start
  fill(l.begin(), l.end(), pair<int, int>{-1,0});
  dfs(0,0,last, adj, l);
  start = last;

  // find end 
  fill(l.begin(), l.end(), pair<int, int>{-1,0});
  fill(r.begin(), r.end(), pair<int, int>{-1,0});
  dfs(start, 0, last, adj, l);
  end = last;

  // calculate distance from end
  dfs(end, 0, last, adj, r);
 
  sort(l.begin(), l.end()); 
  sort(r.begin(), r.end());

  DSU dsu(n);
  vector<int> ans;
  int i=n-1, j=n-1;

  for(int k=n; k>=1; --k){
    while(i>=0 && l[i].first >= k) dsu.join(start, l[i--].second);
    while(j>=0 && r[j].first >= k) dsu.join(end, r[j--].second);
    ans.push_back(dsu.size);
  }
  reverse(ans.begin(), ans.end());

  for(auto val : ans) cout << val << " ";
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t=1; 
  while(t--){
    solve();
  }
}
