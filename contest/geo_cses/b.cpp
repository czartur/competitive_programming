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

typedef long double type;

struct Point{
  type x;
  type y;

  Point() : x(0), y(0) {}
  Point(type x, type y) : x(x), y(y) {}

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y  - p.y); }
  Point& operator-=(const Point& p) { this->x -= p.x; this->y -= p.y; return *this; }

  type operator*(const Point& p) { return x*p.x + y*p.y; } 
  type operator% (const Point& p) { return x*p.y - y*p.x; }
  
  friend Point operator*(const Point& p, type val);
  friend Point operator*(type val, const Point& p);
 
  // 1 means left -1 means right 0 means on the line
  int dir(Point& p, Point& q){
    type ans = (*this - p)%(q - p);
    return (ans > 0) - (ans < 0);
  }
};

Point operator*(const Point& p, type val){
  return Point(p.x*val, p.y*val);
} 

Point operator*(type val, const Point& p){
  return Point(p.x*val, p.y*val);
}

void solve(){
  Point v[4];
  for(int i=0; i<4; i++) cin >> v[i].x >> v[i].y;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
