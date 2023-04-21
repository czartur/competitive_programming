#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N = 200;

int dp[3][N+1][N+1];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while(cin >> n >> k){
    if(n == 0 && k == 0) return 0;
    memset(dp, 0, sizeof(dp));
    vector<pair<int,int>> row(n);
    for(auto& p : row) cin >> p.first >> p.second;

    // 0 --> 0,0 || 1 --> 0,1 || 2 --> 1,0
    // R == 0
      dp[0][0][0] = row[0].first + row[0].second;
      dp[1][1][0] = row[0].first; 
      dp[2][1][0] = row[0].second;
      for(int b = 1; b <= k; ++b) dp[0][b][0] = -INF;
      for(int b = 2; b <= k; ++b) dp[1][b][0] = dp[2][b][0] = -INF;
    for(int r = 1; r < n; ++r){
      // b == 0
      dp[0][0][r] = row[r].first + row[r].second + dp[0][0][r-1];
      dp[1][0][r] = dp[2][0][r] = -INF;
      for(int b = 1; b <= k; ++b){
        dp[0][b][r] = row[r].first + row[r].second + max({dp[0][b][r-1], dp[1][b][r-1], dp[2][b][r-1]});
        dp[1][b][r] = row[r].first + max(dp[0][b-1][r-1], dp[1][b-1][r-1]);
        dp[2][b][r] = row[r].second + max(dp[0][b-1][r-1], dp[2][b-1][r-1]);
      }
    }
    int ans = max({dp[0][k][n-1], dp[1][k][n-1], dp[2][k][n-1]});
    cout << ans << endl;
  }
}
