#include <bits/stdc++.h>
using namespace std;
//Breadth First Search (BFS)
//pode ser usado para medir distâncias
//(arrau de distâncias setado em infinito ao invés do array de visitados)

#define N 100
typedef vector<int> vi;

int vis[N];
vi adj[N]; //lista de adjacência

void bfs(int u){
  queue <int> q;
  q.push(x);
  while(!q.empty()){
    u=q.front();
    vis[u]=1;
    q.pop();
    for(auto v: adj[u]) if(!vis[v]) q.push(v);
  }
}

int main(){

}
