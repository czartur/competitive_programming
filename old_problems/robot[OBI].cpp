#include <bits/stdc++.h>
using namespace std;
#define N 1003
#define pb push_back
#define y1 ya
#define nd second
#define st first

int dist[N];
int x1[N], y1[N], x2[N], y2[N];
vector <int> adj[N], adjw[N];

int fdist(int a, int b){
  int x=0, y=0;
  if(x2[a]<x1[b] || x2[b]<x1[a]) x=max(x1[b]-x2[a], x1[a]-x2[b]);
  if(y2[a]<y1[b] || y2[b]<y1[a]) y=max(y1[b]-y2[a], y1[a]-y2[b]);
  return x+y;
}

void dijkstra(){
  priority_queue <pair<int, int>> pq;
  memset(dist, 63, sizeof(dist));
  dist[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    int u=pq.top().nd;
    int d=-pq.top().st;
    pq.pop();
    if(dist[u]<d) continue;
    for(int i=0; i<adj[u].size(); i++){
      int v=adj[u][i], w=adjw[u][i];
      if(dist[u]+w<dist[v]) {
        dist[v]=dist[u]+w;
        pq.push({-dist[v], v});
      }
    }
  }
}

int main(){
  int n, sx, sy, ex, ey;
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    if(x1[i]>x2[i]) swap(x1[i], x2[i]);
    if(y1[i]>y2[i]) swap(y1[i], y2[i]);
  }

  x1[0]=x2[0]=sx, y1[0]=y2[0]=sy;
  x1[n+1]=x2[n+1]=ex, y1[n+1]=y2[n+1]=ey;

  for(int i=0; i<=n+1; i++){
    for(int j=i+1; j<=n+1; j++){
      adj[i].pb(j), adjw[i].pb(fdist(i, j));
    }
  }

  dijkstra();

  printf("%d\n", dist[n+1]);
}
