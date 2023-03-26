// 2-STAT algorithm using Kosaraju to identify SCC's (strongly conected components)

// ncomp starts at 1 by default (it marks scc's)

// !! INCOMPLETE !! it does not find solutions, just calculates if there is one or not

class Sat_2{
private:
  vector<vector<int>> adj, adj_r;
  vector<int> order, scc; 
  int ncomp, size;

  void dfs(int cur){
    auto& seen = scc; // rename
    seen[cur] = -1;
    for(auto prox : adj[cur]){ 
      if(!seen[prox]) dfs(prox);
    }
    order.push_back(cur);
  }

  void dfs_r(int cur, int comp){
    scc[cur] = comp;
    for(auto prox : adj_r[cur]){
      if(scc[prox] == -1) dfs_r(prox, comp);
    }
  }

public:

  Sat_2(int size, int ncomp = 0) : size{size}, ncomp{ncomp} {
    adj.assign(size, vector<int>());
    adj_r.assign(size, vector<int>());
    scc.assign(size, 0);
    order.reserve(size);
  }

  void add_or(int a, int b){
    adj[a^1].push_back(b); adj_r[b].push_back(a^1);
    adj[b^1].push_back(a); adj_r[a].push_back(b^1);
  } 

  bool possible(){
    auto& seen = scc;
    for(int cur = 0; cur < size; ++cur) {
      if(!seen[cur]) dfs(cur);
    }

    reverse(order.begin(), order.end());
    for(auto cur : order) {
      if(scc[cur] == -1) dfs_r(cur, ++ncomp);
    }

    bool ok = 1;
    for(int cur = 0; cur < size; cur += 2) ok &= (scc[cur] != scc[cur^1]);
    return ok;
  }
};