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

void solve(){
  int q; cin >> q;
  ll hp = 1, hg = LINF;
  while(q--){
    int op; cin >> op;
    if(op == 1){
      ll a, b, n; cin >> a >> b >> n;
      ll nova_hg = (n-1)*(a-b) + a;
      ll nova_hp = (n>1) ? (n-1)*(a-b) + b+1 : 1;
      if(nova_hg < hp || nova_hp > hg) cout << 0 << " ";
      else{
        cout << 1 << " ";
        hg = min(hg, nova_hg);
        hp = max(hp, nova_hp);
      }
    }else { // op == 2
      ll a, b; cin >> a >> b;
      ll np = 1 + (hp < a ? 0 : (hp-b-1)/(a-b));
      ll ng = 1 + (hg < a ? 0 : (hg-b-1)/(a-b));
      if(np != ng) cout << -1 << " ";
      else cout << np << " ";
    }
  }
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