#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int s, p, m, n;  cin >> s >> p >> m >> n;
  vector<int> t(n);
  for(auto &val : t) cin >> val;

  vector<ll> dp(n);
  dp[0] = min(s, p);
  for(int i=1; i<n; ++i){
    // period
    int idx = lower_bound(t.begin(), t.end(), t[i]-m+1) - t.begin();
    dp[i] = p + ((idx > 0) ? dp[idx-1] : 0);

    // single
    dp[i] = min(dp[i], s + dp[i-1]);
  }

  cout << dp[n-1] << endl;
}
