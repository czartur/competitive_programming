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
  ll n, k, x; cin >> n >> k >> x;
  vector<ll> a(n+2), psum(n+2);
  for(int i=1; i<=n; i++){
    cin >> a[i]; a[i]-=x;
    psum[i] = psum[i-1] + a[i];
  }

  // kadane left - right
  vector<ll> lsum(n+2), rsum(n+2);
  ll cur=0, glob=0;
  for(int i=1; i<=n; i++){
    cur = max(0LL, cur+a[i]);
    lsum[i] = glob = max(cur, glob);
  }
  glob=cur=0;
  for(int i=n+1; i>0; i--){
    cur = max(0LL, cur+a[i]);
    rsum[i] = glob = max(cur, glob);
  }

  ll ans = 0;
  for(int i=1; i+k-1<=n; i++){
    for(int l=i; l<i+k; l++){
      for(int r=l+1; r<i+k; r++){
        ll cur=psum[r]-psum[l-1] + 2*x*(r-l+1);
        if(l==i) cur+=lsum[i-1];
        if(r==i+k-1) cur+=rsum[i+k];
        ans = max(ans, cur);
      } 
    }
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
