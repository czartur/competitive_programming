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

map<string, pair<int,int>> DIR = {{"DR", {1, 1}}, {"DL",{1, 0}}, {"UR",{0, 1}}, {"UL", {0, 0}}};

int run(int i, int j, string sdir, int x, int y, map<string, vector<vector<bool>>> &vis, int n, int m){
  auto&v = vis[sdir];
  pair<int,int> new_dir = DIR[sdir];

  if(v[i][j]) return -INF;
  v[i][j] = 1;
  if(i == x && j == y) return 0;
  
  if((i == n && sdir[0] == 'D')||(i == 1 && sdir[0] == 'U')) new_dir.first ^= 1;
  if((j == m && sdir[1] == 'R')||(j == 1 && sdir[1] == 'L')) new_dir.second ^= 1;

  string snew_dir;
  for(auto& p : DIR) if(p.second == new_dir) snew_dir = p.first;

  return (new_dir != DIR[sdir]) + run(i + new_dir.first- !new_dir.first, j + new_dir.second - !new_dir.second, snew_dir,x,y,vis,n,m);
}
void solve(){
  int n, m, i1, j1, i2, j2;
  string sdir;
  cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> sdir;
  map<string, vector<vector<bool>>> vis;
  for(auto& dir : DIR) vis[dir.first] = vector<vector<bool>>(n+1, vector<bool>(m+1));
  int ans = run(i1, j1, sdir, i2, j2, vis, n, m);
  if(ans >=0) cout << ans << endl;
  else cout << -1 << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
