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
const int N = 1e5 + 5;

struct rect{
  int w, h, x, y;
  
  int area(){ return w*h; }
  bool overlap(const rect& r){
    return !((r.x >= x+w) || (r.x+r.w) <= x || (r.y >= y+h) || (r.y+r.h <= y));
  }
};

void bt(int pos, int &ans, vector<rect> &used, vector<rect> &retangulos){
  if(pos == retangulos.size()){
    int area = 0;
    for(auto& u : used) area+=u.area();
    ans = max(ans, area);
    return;
  }
  
  rect cur = retangulos[pos];
  
  // overlapping test
  bool ok = 1; 
  for(auto& u : used) if(cur.overlap(u)) {ok = 0; break; }
  
  // include cur
  if(ok){
    used.push_back(cur);
    bt(pos+1, ans, used, retangulos);
    used.pop_back();
  }
  
  // without cur
  bt(pos+1, ans, used, retangulos);
}

void solve(int n){
  vector<rect> retangulos(n), used;
  used.reserve(n);

  for(auto& r : retangulos){
    cin >> r.w >> r.h >> r.x >> r.y;
  }

  int ans = 0;
  bt(0, ans, used, retangulos);
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    int n; cin >> n;
    if(n == 0) return 0;
    solve(n);
  }
}
