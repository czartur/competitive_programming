#include <bits/stdc++.h>
using namespace std;
#define N 100

int main(){
  int dp[N], v[N], n, lis=0;
  memset(dp, 63, sizeof dp);
  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &v[i]);
  for (int i=0; i<n; ++i) {
    // increasing: lower_bound
    // non-decreasing: upper_bound
    int j = lower_bound(dp, dp+lis, v[i]) - dp;
    dp[j] = min(dp[j], v[i]);
    lis = max(lis, j+1);
  }
  printf("L.I.S is %d\n", lis);
}
