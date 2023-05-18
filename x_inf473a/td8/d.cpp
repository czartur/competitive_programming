#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
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

const int L = 0;
const int R = 1;

class Circle{
  private:

  int distance(const Circle &circle){
    return (x-circle.x)*(x-circle.x) + (y-circle.y)*(y-circle.y);
  }

  public:
  
  int x, y, r;

  Circle(int x_, int y_, int r_): x(x_), y(y_), r(r_) {}

  bool intersect(const Circle &circle){
    return distance(circle) <= (r + circle.r)*(r + circle.r);      
  }

  bool left(){ return x - r < 0; }
  bool right(){ return x + r > 200; }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<Circle> v;
  for(int i = 0; i < n; ++i){
    int x, y, r; cin >> x >> y >> r;
    v.push_back(Circle(x,y,r));
  }

  DSU uf(n+2);

  int k = 0;
  for(int i = 0; i < n; ++i){
    if(v[i].left()) uf.join(i+2, L);
    if(v[i].right()) uf.join(i+2, R);

    for(int j = 0; j < i; ++j){
      if(v[i].intersect(v[j])) uf.join(i+2, j+2); 
    }
    if(uf.find(L) == uf.find(R)) break;
    ++k;
  }

  cout << k << endl;

}