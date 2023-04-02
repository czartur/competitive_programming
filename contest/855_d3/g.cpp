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

int h[N];
vector<int> adj[N];
hash<string> hash_code;

void dfs(int u, int pai){
  vector<int> ch;
  for(auto v : adj[u]){
    if(v == pai) continue;
    dfs(v , u);
    ch.push_back(h[v]);
  }
  sort(ch.begin(), ch.end());
  string codify = "<";
  for(auto code : ch) codify += "|" + to_string(code) + "|";
  codify+= ">";
  h[u] = hash_code(codify);
}

bool isSym(int u, int pai){
  unordered_map<int, int> m;
  for(auto v : adj[u]){
    if(v == pai) continue;
    if(m.count(h[v])) m.erase(h[v]);
    else m[h[v]] = v;  
  }
  return m.size() == 1 ? isSym(m.begin()->second, u) : m.empty(); 
}

void solve(){
  int n; cin >> n;
  for(int i=0; i<n; i++) adj[i].clear();
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0,0);
  if(isSym(0,0)) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
