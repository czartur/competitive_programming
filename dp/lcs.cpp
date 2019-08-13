#include <bits/stdc++.h>
using namespace std;
//Longest Common subsequence
//set dp to -1

int dp[N][N];
string a, b;
int lcs(int i, int j){ //string lenghts considered
  if(!i || !j) return dp[i][j]=0;
  if(dp[i][j]==-1) return dp[i][j];
  if(a[i-1]==b[j-1]) return dp[i][j]=1+lcs(i-1, j-1);
  return dp[i][j]=max(lcs(i-1,j), lcs(i,j-1));
