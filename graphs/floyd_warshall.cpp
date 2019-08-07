#include <bits/stdc++.h>
using namespace std;
//Floyd Warshal
//GOAL: calculate the length of shortest path between all pair of nodes

//initially set distances using edges length (reading step)
//before this, also set the dist matrix to INF
int dist[N][N];
void floyd(){
  for(int k=1; k<=n; k++){
    for(int j=1; j<=n; j++){
      for(int i=1; i<=n; i++){
        d[j][i]=d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}
