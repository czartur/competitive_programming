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
  double n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
  double g1 = max(abs(x1-(n/2.f + 0.5)), abs(y1-(n/2.f + 0.5)));
  double g2 = max(abs(x2-(n/2.f + 0.5)), abs(y2-(n/2.f + 0.5)));
  g1+=0.5;
  g2+=0.5;
 cout << (int) abs(g1-g2) << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}