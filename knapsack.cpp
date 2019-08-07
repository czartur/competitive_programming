#include <bits/stdc++.h>
using namespace std;
#define N 100

//Knapsack problem
//GOAL: returns maximum total value while
//      inserting objects with size and
//      value in a fixed capacity bag

//set dp to -1
//Col -> size used, Row -> item number
int dp[N][N], wt[N], val[N];
int func(int i, int j){
  if(i==1){
    if(j<wt[i]) return dp[i][j]=0;
    else return dp[i][j]=val[i];
  }
  if(dp[i][j]!=-1) return dp[i][j];
  return dp[i][j]=max(func(i-1, j), val[i]+func(i-1, j-wt[i]));
}
