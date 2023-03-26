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

void bt(int pos, int last, int total, unordered_set<int> &used, 
        int& cnt, vector<int> &fav, unordered_map<int, unordered_set<int>> &forbid)
{
  if(pos == total) {++cnt; return;}
  for(int color=0; color<total; ++color){
    // db(color);
    if(pos && (used.count(color) || forbid[last].count(color))) continue;
    
    if(!cnt) fav.push_back(color);
    used.insert(color);
    bt(pos+1, color, total, used, cnt, fav, forbid);
    used.erase(color); 
    if(!cnt) fav.pop_back();
  }
}

void solve(){
  int n; cin >> n;
  int idn = -1;
  unordered_map<string, int> id;
  unordered_map<int, string> cor;
  for(int i=0; i<n; i++) {
    string color; cin >> color;
    id[color] = ++idn;
    cor[idn] = color;
  }
  
  int m; cin >> m;
  unordered_map<int, unordered_set<int>> forbid;
  for(int i=0; i<m; i++){
    string a, b; cin >> a >> b;
    forbid[id[a]].insert(id[b]);
    forbid[id[b]].insert(id[a]);
  }
  
  int cnt = 0;
  vector<int> fav;
  unordered_set<int> used;
  bt(0, -1, n, used, cnt, fav, forbid);
  
  cout << cnt << endl;
  for(auto color : fav) cout << cor[color] << " ";
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    solve(); 
  }
}
