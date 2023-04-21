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

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int N =1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> p(n);
  for(auto& val : p) cin >> val;
  vector<vector<int>> dp(n, vector<int>(2*1000+1));

  dp[0][0] = dp[0][p[0]] = 1;
  for(int i=1; i<n; ++i){
    for(int w=0; w<=2*1000; ++w){
      dp[i][w] = dp[i-1][w];
      if(w-p[i] >= 0) dp[i][w] |= dp[i-1][w-p[i]]; 
    }
  }

  int ans = 0;
  for(int w=0; w<=2*1000; ++w) 
    if(dp[n-1][w] && (abs(w-1000) <= abs(ans-1000))) ans = w;
  cout << ans << endl;
}
