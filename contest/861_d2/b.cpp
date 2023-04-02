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
  ll n, m; cin >> n >> m;
  vector<vector<ll>> num(m, vector<ll>(n));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> num[j][i];
    }
  }

  for(int j=0; j<m; ++j) sort(num[j].begin(), num[j].end());
  
  ll ans = 0;
  for(int j=0; j<m; ++j){
    auto &cur = num[j];
    ll sum = cur[0];
    for(ll i=1; i<n; ++i) ans += cur[i]*i - sum, sum += cur[i];
  }
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
