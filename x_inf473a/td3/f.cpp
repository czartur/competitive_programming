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

struct point{
  public:
  int x;
  int y;
  point operator+(const point &q){
    x += q.x;
    y += q.y;
    return *this;
  }
};

const vector<point> DIR = {{-1,-1}, {-1,1}, {1,-1}, {1,1}, {1,0}, {-1,0}, {0,1}, {0,-1}}; 

void add(int qx, int qy, vector<vector<int>> &tab){
  int x = tab.size(), y = tab[0].size();
  for(point dir : DIR){
    point aux {qx, qy};
    while(aux.x < x && aux.y < y && aux.x >=0 && aux.y >=0){
      ++tab[aux.x][aux.y];
      aux = aux + dir;  
    }
  }
}

void solve(int x, int y, int n){
  vector<bool> row(x), col(y);
  vector<bool> dp(x+y), ds(x+y); 
  // x+y is cte for main diagonal 
  // x-y is cte for second diagonal
  while(n--){ 
    int qx, qy; cin >> qx >> qy;
    --qx, --qy;
    row[qx] = col[qy] = 1;
    dp[qx+qy] = ds[qx-qy + y] = 1;
  }
  int ans = 0;
  for(int xx=0; xx<x; ++xx){
    for(int yy=0; yy<y; ++yy){
      ans += (!row[xx] && !col[yy] && !dp[xx+yy] && !ds[xx-yy+y]);
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    int x, y, n;
    cin >> x >> y >> n;
    if(!x && !y && !n) return 0;
    solve(x, y, n);
  }
}
