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
const int N =5e4+5;

// int can(int &day, vector<vector<int>> &d, vector<int> &p){
//   unordered_set<int> used;
//   for(int i=0; i<d.size(); i++){
//     used.insert(d[i][p[i]]);
//   }

//   if(used.size() == d.size()) return 0;
  
//   if(day == d.size()) return -1;
//   if(p[day]+1 == d[day].size()) ++day;
//   else ++p[day];
//   return 1; 
// }

int hp[N];
void solve(){
  int m; cin >> m;
  vector<vector<int>> d(m);
  for(int i=0; i<m; i++){
    int n; cin >> n;
    d[i].resize(n);
    for(auto& a: d[i]) {
      cin >> a;
      hp[a] = i;
    }
  }

  vector<int> p;
  for(int i=0; i<m; i++){
    for(auto a : d[i]) if(hp[a] == i) {p.push_back(a); break;}
  }

  for(int i=0; i<m; i++){
    for(auto a: d[i]) hp[a] = 0;
  }

  if(p.size() < m) cout << -1 << endl;
  else {
    for(auto pp : p) cout << pp << " ";
    cout << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
