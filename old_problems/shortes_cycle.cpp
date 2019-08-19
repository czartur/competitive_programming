#include <bits/stdc++.h>
using namespace std;
//580_div 2... problem D (shortest cycle)
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define st first
#define nd second
typedef long long ll;

vector <int> adj[100110], bdj[100110];
int dist[100110];
pair <int, int> edge[70];
 void dijkstra(int s, int e){
  memset(dist, 63, sizeof(dist));
  queue <int> q;
  q.push(s);
  dist[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=0; i<bdj[u].size(); i++){
      int v=bdj[u][i];
      //printf("u=%d, v=%d\n", u, v);
      if(u==s && v==e) continue;
      if(dist[u]+1<dist[v]){
        dist[v]=1+dist[u];
        q.push(v);
      }
    }
  }
}
void printadj(){
  for(int i=1; i<=63; i++) {
    printf("%d:\n", i);
    for(int j=0; j<adj[i].size(); j++) {
      printf("%d ", adj[i][j]-100);
    }
    printf("\n");
  }
}
int main(){
  int n;
  ll v[100005];
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%lld", &v[i]);
    ll k=v[i];
    int j=1;
    while(k){
      if(k%2) adj[j].pb(i+100), adj[i+100].pb(j);
      k=k>>1;
      j++;
    }
  }

  int cnt=1;
  for(int i=1; i<=63; i++){
    if(adj[i].size()>=3) {
      printf("3\n");
      return 0;
    }
    else if(adj[i].size()==2){
      edge[cnt++]=mp(adj[i][0], adj[i][1]);
      bdj[adj[i][1]].pb(adj[i][0]);
      bdj[adj[i][0]].pb(adj[i][1]);
    }
  }

  // printadj();

  int m=INF;

  for(int i=1; i<cnt; i++){
    // printf("%d %d\n", edge[i].st, edge[i].nd);
    dijkstra(edge[i].st, edge[i].nd);
    m=min(m, 1+dist[edge[i].nd]);
  }
  if(m!=INF) printf("%d\n", m);
  else printf("-1\n");
}
