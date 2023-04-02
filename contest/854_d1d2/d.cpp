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
  int n, k; cin >> n >> k; 
  vi a(n), cold(k+1), hot(k+1);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=1; i<=k; i++) cin >> cold[i];
  for(int i=1; i<=k; i++) cin >> hot[i];

  vi last(n, -1), p(k+1, -1);
  vector<ll> psum(n+1);
  for(int i=0; i<n; i++){
    int number = a[i];
    last[i] = p[number];
    p[number] = i;

    if(i>0 && a[i] == a[i-1]) psum[i] = psum[i-1] + hot[number];
    else if(i>0) psum[i] = psum[i-1] + cold[number];
    else psum[i] = cold[number];
  } 

  vector<ll> dp(n);
  dp[0] = cold[a[0]];
  for(int i=1; i<n; i++){
    if(a[i] == a[i-1]) dp[i] = dp[i-1] + hot[a[i]];
    else  dp[i] = dp[i-1] + cold[a[i]];
    if(~last[i] && a[i] != a[i-1]){
      dp[i] = min(dp[i], dp[last[i]+1] + (psum[i-1] - psum[last[i]+1]) + hot[a[i]]);
    }
  }
  cout << dp[n-1] << endl; 
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    solve();
  }
}
