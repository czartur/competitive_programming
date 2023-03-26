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

void dfs(int cur, vector<int> &order, vector<int> &seen, vector<vector<int>> &adj){
  seen[cur] = -1;
  for(auto prox : adj[cur]){ 
    if(!seen[prox]) dfs(prox, order, seen, adj);
  }
  order.push_back(cur);
}

void dfs_r(int cur, int ncmp, vector<int> &cmp, vector<vector<int>> &adj_r){
  cmp[cur] = ncmp;
  for(auto prox : adj_r[cur]){
    if(cmp[prox] == -1) dfs_r(prox, ncmp, cmp, adj_r);
 }
}

void add_or(int a, int b, vector<vector<int>> &adj, vector<vector<int>> &adj_r){
  adj[a^1].push_back(b); adj_r[b].push_back(a^1);
  adj[b^1].push_back(a); adj_r[a].push_back(b^1);
}
void solve(){ 
  int S, A, m; cin >> S >> A >> m;
  int size = (A+S)<<1;
  vector<vector<int>> adj(size), adj_r(size);

  int ss, as, sd, ad;
  int dir_s, dir_a;
  for(int i=0; i<m; i++){
    cin >> ss >> as >> sd >> ad;
    dir_s = (as == ad ? -1 : (as < ad));
    dir_a = (ss == sd ? -1 : (ss < sd));

    // odd ~ true ~ increasing direction
    --ss, --as, --sd, --ad;
    ss<<=1, as<<=1, sd<<=1, ad<<=1;
    ss^=dir_s, as^=dir_a, sd^=dir_s, ad^=dir_a;
    ss += A<<1; sd += A<<1; // offset

    if(dir_s == -1 && dir_a == -1) continue;
    
    if(dir_s == -1) add_or(as, as, adj, adj_r);
    else if(dir_a == -1) add_or(ss, ss, adj, adj_r);
    else {
      // (ss and ad) or (as and sd) 
      // == (ss or as) and (ss or sd) and (ad or as) and (ad or sd)
      add_or(ss, as, adj, adj_r);
      add_or(ss, sd, adj, adj_r);
      add_or(ad, as, adj, adj_r);
      add_or(ad, sd, adj, adj_r);
    }
  }

  vector<int> order;
  vector<int> seen(size);
  order.reserve(size);
  for(int cur=0; cur<size; ++cur) {
    if(!seen[cur]) dfs(cur, order, seen, adj);
  }

  auto &cmp = seen; 
  int ncmp = 0;
  reverse(order.begin(), order.end());
  for(auto cur : order) {
    if(cmp[cur] == -1) dfs_r(cur, ++ncmp, cmp, adj_r);
  }

  bool ok = 1;
  for(int cur=0; cur<size; cur+=2) ok &= (cmp[cur] != cmp[cur^1]);
  
  cout << (ok ? "Yes" : "No") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) solve();
}
