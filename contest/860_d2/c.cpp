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

ll gcd(ll a, ll b){
 return b ? gcd(b, a%b) : a;
}

void solve(){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; ++i) cin >> a[i] >> b[i];
  
  ll cur = a[0]*b[0], ans = 1;
  ll lcm = b[0];
  for(int i=1; i<n; ++i){
    if(gcd(a[i]*b[i], cur) % ((b[i]*lcm)/gcd(b[i], lcm))) ++ans, cur = a[i]*b[i], lcm = b[i]; 
    else cur = gcd(a[i]*b[i], cur), lcm = (b[i]*lcm)/gcd(b[i], lcm);
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
