#include <bits/stdc++.h>
using namespace std;
#define N 100
#define pb push_back

//Lowest Common Ancestor
//GOAL: o nome já fala
//Trick: sparse table baseado nas alturas relativas (i+2^j)
//30 is a good limit
vector <int> adj[N];
int h[N], anc[30][N];

void bfs(int x){ // find relative height of nodes
  queue <int> q;
  q.push(x);
  h[x]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v:adj[u]){
      if(!h[v] && v!=x) h[v]=h[u]+1, q.push(v), anc[0][v]=u;
    }
  }
}

void build (int n){
  for(int j=1; j<=30; j++){ //se botar j=0  da errado ><
    for(int i=1; i<=n; i++){
      anc[j][i]=anc[j-1][anc[j-1][i]];
    }
  }
}

int lca(int u, int v){
  int ans=-1;
  //equal heights first
  if(h[v]>h[u]) swap(u,v); //keep u always bigger
  for(int j=30; j>=0; j--){
    if(h[u]-(1<<j)>=h[v]) u=anc[j][u];
  }

  for(int j=30; j>=0; j--){
    if(anc[j][u]!=anc[j][v]){
      return ans;
    }
    ans=anc[j][u];
  }
}

int main(){
  int n, a, b, x;
  scanf("%d", &n);
  //Tree: number of edfes = nodes-1
  for(int i=1; i<n; i++){
    scanf("%d %d", &a, &b);
    adj[a].pb(b), adj[b].pb(a);
  }
  scanf("%d %d %d", &x, &a, &b);
  bfs(x), build(n);
  printf("%d\n", lca(a, b));
}
