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

typedef long double ld;

struct Point{
  long double x;
  long double y;

  Point() : x(0), y(0) {}
  Point(ld x, ld y) : x(x), y(y) {}

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y  - p.y); }
  Point& operator-=(const Point& p) { this->x -= p.x; this->y -= p.y; return *this; }

}; 

ld cross(Point p, Point q) {return p.x*q.y - q.x*p.y; }

void solve(){
  Point p[3]; 
  for(int i=0; i<3; i++) { cin >> p[i].x  >> p[i].y; }
  p[0]-=p[2], p[1]-=p[2];
  ll prod = cross(p[0], p[1]);
  if(prod > 0) cout << "LEFT" << endl;
  else if(prod < 0) cout << "RIGHT" << endl;
  else cout << "TOUCH" << endl;
} 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
