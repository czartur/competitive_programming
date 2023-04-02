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
  ll n, c, d; cin >> n >> c >> d;
  ll off = 0;
  set<ll> used;
  for(int i=0; i<n; ++i){
    int a; cin >> a;
    if(used.count(a)) off += c;
    else used.insert(a); 
  }
  
  ll falta = 0, apaga = used.size(), last = 0;
  ll ans = apaga*c + d;
  for(auto a : used){
    // db(a);
    --apaga;
    falta += a-last-1;
    // db(falta);
    // db(apaga);
    ans = min(ans, falta*d + apaga*c);
    last = a;
    // db(ans);
  }
  // db(ans);
  cout << ans + off << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
