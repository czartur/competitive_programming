#include <bits/stdc++.h>
using namespace std;
//Dijkstra
//GOAL: calculate shortest distance between a node and all others

//Remember to use negative distances on priority queue (sorting)
int dist[N];
vi adj[N], adjw[N];
void dijkstra(int x){
  priority_queue(pii) pq;
  pq.push({0, x});
  dist[x]=0;
  while(!pq.empty()){
    int u=pq.top().nd;
    int d=-pq.top().st;
    if(d>dist[u]) continue; //you always forget this step...
    for(int i=0; i<adj[u].size(); i++){
      int v=adj[u][i], w=adjw[u][i];
      if(dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push({-dist[v], v});
      }
    }
  }
}
