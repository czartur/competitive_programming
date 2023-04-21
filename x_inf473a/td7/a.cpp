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

  int f, s, g, u, d; 
  cin >> f >> s >> g >> u >> d;

  vector<vector<int>> adj(f+1);
  vector<int> vis(f+1, -1);
  for(int i = 1; i <= f; ++i){
    if(u !=0 && (i + u <= f)) adj[i].push_back(i+u);
    if(d !=0 && (i-d >= 1)) adj[i].push_back(i-d);
  }

  // BFS
  queue<int> q;
  q.push(s); vis[s] = 0;
  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(auto prox : adj[cur]){
      if(~vis[prox]) continue;
      vis[prox] = 1+vis[cur];
      q.push(prox);
    }
  }

  if(~vis[g]) cout << vis[g] << endl;
  else cout << "use the stairs" << endl;
}
