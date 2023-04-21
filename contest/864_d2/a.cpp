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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =1e5+5;

void solve(){
  int n, m; cin >> n >> m;
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  
  int a=4, b=4;
  a-=(x1==1) + (x1==n) + (y1==1) + (y1==m);
  b-=(x2==1) + (x2==n) + (y2==1) + (y2==m);
  cout << min(a,b) << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve(); 
  }
}