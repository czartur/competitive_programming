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

struct route{
  int ss, as, sd, ad; 
};

void bt(int pos, bool &ans, vector<int> &street, vector<int> &avenue, vector<route> &routes){
  
  // cout << ".........." << endl;
  // db(pos);
  // for(auto s : street) cout << s << " ";
  // cout << endl;
  // for(auto a : avenue) cout << a << " ";
  // cout << endl;
  // cout << ".........." << endl;

  if(pos == routes.size()) { ans=1; return; }

  route& cur = routes[pos];

  // direction to follow in object
  int dir_s = (cur.as == cur.ad ? -1 : (cur.as < cur.ad));
  int dir_a = (cur.ss == cur.sd ? -1 : (cur.ss < cur.sd));

  // same crossing
  if(dir_s == -1 && dir_a == -1) {
    bt(pos+1, ans, street, avenue, routes);
    return;
  }

  // same street
  if(dir_a == -1 && street[cur.ss] != !dir_s){
    bool change_s = (street[cur.ss] == -1);
    if(change_s) street[cur.ss] = dir_s; 
    bt(pos+1, ans, street, avenue, routes);
    if(change_s) street[cur.ss]= -1;
    return;
  }

  // same avenue
  if(dir_s == -1 && avenue[cur.as] != !dir_a){
    bool change_a = (avenue[cur.as] == -1);
    if(change_a) avenue[cur.as] = dir_a; 
    bt(pos+1, ans, street, avenue, routes);
    if(change_a) avenue[cur.as]= -1;
    return;
  }

  if(~dir_s && ~dir_a){
    // street --> avenue
    if(street[cur.ss] != !dir_s && avenue[cur.ad] != !dir_a){
      bool change_s = (street[cur.ss] == -1);
      bool change_a = (avenue[cur.ad] == -1);
      if(change_s) street[cur.ss] = dir_s;
      if(change_a) avenue[cur.ad] = dir_a;
      bt(pos+1, ans, street, avenue, routes);
      if(change_s) street[cur.ss] = -1;
      if(change_a) avenue[cur.ad] = -1;
    }

    if(ans) return;
    
    // avenue --> street
    if(avenue[cur.as] != !dir_a && street[cur.sd] != !dir_s){
      bool change_a = (avenue[cur.as] == -1);
      bool change_s = (street[cur.sd] == -1);
      if(change_a) avenue[cur.as] = dir_a;
      if(change_s) street[cur.sd] = dir_s;
      bt(pos+1, ans, street, avenue, routes);
      if(change_a) avenue[cur.as] = -1;
      if(change_s) street[cur.sd] = -1;
    } 
  }
}
void solve(){
  int S, A, m;
  cin >> S >> A >> m;
  vector<route> routes(m);
  vector<int> street(S+1, -1), avenue(A+1, -1);
  for(auto& r : routes) 
    cin >> r.ss >> r. as >> r.sd >> r.ad;

  bool ans = 0;
  bt(0, ans, street, avenue, routes);
  cout << (ans ? "Yes" : "No") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while(t--) solve(); 
  
}
