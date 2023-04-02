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

ll close(ll b, vector<ll> &coef){
  if(b < coef[0]) return coef[0];
  if(b > coef.back()) return coef.back();
  int l = 0, r = coef.size()-1;
  while(l <= r){
    int mid = (l+r)/2;
    
    if(coef[mid] == b) return b;
    if(b < coef[mid]) r = mid-1;
    else l = mid+1;
  }
  return (coef[l] - b) < (b - coef[r]) ? coef[l] : coef[r];
}

void solve(){
  int n, m; cin >> n >> m;
  vector<ll> coef(n);
  for(auto& k : coef) cin >> k;
  sort(coef.begin(), coef.end());

  while(m--){
    ll a, b, c; cin >> a >> b >> c;
    ll k = close(b, coef);
    ll dif = b-k;
    if(dif*dif < 4*a*c) {cout << "YES" << endl << k << endl;}
    else cout << "NO" << endl;
    // cout << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
