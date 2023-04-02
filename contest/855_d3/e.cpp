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
const int N =1e5+5;


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

void solve(){
  int n, k; cin >> n >> k;
  string s, t; cin >> s >> t;

  DSU dsu(n);
  for(int i=0; i<n; i++){
    if(i+k+1 < n) dsu.join(i, i+k+1); 
    if(i+k < n) dsu.join(i, i+k);
  }

  // we just need to check if they have the same elements in each set
  vector<vector<char>> es(n), et(n);
  for(int i=0; i<n; i++){
    int head = dsu.find(i);
    es[head].pb(s[i]);
    et[head].pb(t[i]);
  }

  bool ok = 1;
  for(int i=0; i<n; i++){
    sort(es[i].begin(), es[i].end());
    sort(et[i].begin(), et[i].end());
    ok &= es[i] == et[i];
  } 
  if(ok) cout << "Yes" << endl;
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
