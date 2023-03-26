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

int ans = inf;

void print(int cur, vector<vector<int>> &groups, unordered_map<int, string> &word){
  cout << endl << "[" << word[cur] << "]" << groups.size() << " groups" << endl;
  for(auto& group : groups){
    if(group.empty()) cout << "-";
    else for(auto i : group) cout << word[i] << " "; 
    cout << endl;
  }
  cout << endl;
}

void bt(int cur, int total, vector<vector<int>> &groups, vector<vector<bool>> &hate){
  if(!total) return;
  if(cur == total) { ans = (int)groups.size(); return; }

  int size = groups.size();
   
  if(size >= ans) return;
  // put cur in some existing group
  for(int i=0; i<size; ++i){
    // check if someone in group hate cur
    bool ok = 1; 
    for(auto member : groups[i]) if(hate[cur][member]) {ok = 0; break; } 
    if(!ok) continue;

    groups[i].push_back(cur);
    bt(cur+1, total, groups, hate);
    groups[i].pop_back();
  }

  if(size >= ans) return;
  // create a new group
  groups.push_back({cur});
  bt(cur+1, total, groups, hate);
  groups.pop_back();
}

void solve(int n, int m){
  int idn = -1;
  unordered_map<string, int> id;
  unordered_map<int, string> word;
  vector<vector<bool>> hate(n, vector<bool>(n));
  
  for(int i=0; i<m; i++){
    string a, b; cin >> a >> b;
    if(!id.count(a)) {id[a] = ++idn; word[idn] = a; }
    if(!id.count(b)) {id[b] = ++idn; word[idn] = b; }

    hate[id[a]][id[b]] = true;
    hate[id[b]][id[a]] = true;
  }

  int total = ++idn;

  if(total == 0)  { cout << (n>0) << endl; return; }
  ans = total; 

  vector<vector<int>> groups;
  bt(0, total, groups, hate);
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while(true){
    int n, m; cin >> n >> m;
    if(n == 0 && m ==0) return 0;
    solve(n, m);
  } 
}