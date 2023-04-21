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

vector<int> jump_pos(int i, int j, vector<string> &grid){
  vector<int> ans;
  int k = grid[i][j] - '0';
  int m = grid[0].size();
  int n = grid.size(); 

  if(i+k < n) ans.push_back((i+k)*m +j);
  if(i-k >= 0) ans.push_back((i-k)*m + j);
  if(j+k < m) ans.push_back(i*m + j+k);
  if(j-k >= 0) ans.push_back(i*m + j-k);

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 

  int n, m; cin >> n >> m;
  vector<string> grid(n);
  for(auto& row : grid) cin >> row;

  vector<vector<int>> adj(n*m);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      vector<int> jump = jump_pos(i, j, grid);
      for(auto pos : jump){
        adj[i*m +j].push_back(pos);
      }
    }
  }

  // BFS
  queue<int> q;
  q.push(0);
  vector<int> vis(n*m, -1);
  vis[0] = 0;

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(auto next : adj[cur]){
      if(~vis[next]) continue;
      q.push(next);
      vis[next] = 1 + vis[cur];
    }
  }

  cout << vis[n*m-1] << endl;
}
