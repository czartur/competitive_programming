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
const int MOD = 998244353;
const int N =1e6+6, M = 2e3+30;
bool cmp[N];
ll fat[N], vis[N];
ll dp[2*M][M];

void build(){
  cmp[1] = 1;
  for(ll i=2; i<N; i++) if(!cmp[i]){
    for(ll j=i*i; j<N; j+=i) cmp[j]=true;
  }

  fat[0]=1;
  for(ll i=1; i<N; i++) fat[i] = (fat[i-1]*i)%MOD; 
}

ll fexp(ll b, ll e){
  ll ans = 1;
  while(e){
    if(e&1) ans=(ans*b)%MOD;
    e/=2;
    b=(b*b)%MOD;
  }
  return ans;
}

inline pair<ll, ll> inv_fat(ll x){ return make_pair(fexp(fat[vis[x]], MOD-2), fexp(fat[vis[x]-1], MOD-2)); }

void solve(){
  build();
  int n; cin >> n;
  vector<pair<ll, ll>> primes, comps;
  for(int i=0; i<2*n; i++) {
    int a; cin >> a;
    vis[a]++;
    if(vis[a]>1) continue;
    cmp[a] ? comps.push_back({a, 0}) : primes.push_back({a, 0}); 
  }
  
  if(primes.size() < n) {cout << 0 << endl; return;}

  for(int i=0; i<comps.size(); i++) comps[i] = inv_fat(comps[i].first);
  for(int i=0; i<primes.size(); i++) primes[i] = inv_fat(primes[i].first);

  dp[0][0] = primes[0].first;
  dp[0][1] = primes[0].second;

  for(int i=1; i<primes.size(); i++){ 
    dp[i][0] = primes[i].first*dp[i-1][0]%MOD;
    for(int k=1; k<=n; k++){
      dp[i][k] = (primes[i].first*dp[i-1][k]%MOD + primes[i].second*dp[i-1][k-1]%MOD)%MOD;
    }
  }

  ll ans = fat[n];
  for(auto c: comps){
    ans = ans*c.first%MOD;
  }

  ans = ans*dp[primes.size()-1][n]%MOD;
  cout << ans << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t=1;
  while(t--){
    solve();
  }
}
