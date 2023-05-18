#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q, s;
  while(cin >> n >> m >> q >> s){
    if(n + m + q + s == 0) return 0;
    vector<vector<pair<int,int> > > adj(n);
    vector<int> dist(n, INF);
    while(m--){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      // adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
      auto p = pq.top();
      int d = p.first, u = p.second;
      pq.pop();

      if(dist[u] < d) continue;

      for(pair<int,int> p : adj[u]){
        int v = p.first;
        int w = p.second;
        if(dist[v] > dist[u] + w){
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }

    while(q--){
      int v; cin >> v;
      if(dist[v] == INF) cout << "Impossible" << endl;
      else cout << dist[v] << endl;
    }
  }
} 