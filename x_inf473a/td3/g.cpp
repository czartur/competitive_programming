#include <bits/stdc++.h>
using namespace std;

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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    int S, A, m; cin >> S >> A >> m;
    Sat_2 manhattan((A+S)<<1);
    
    int ss, as, sd, ad, dir_s, dir_a;
    while(m--){
      cin >> ss >> as >> sd >> ad;
      dir_s = (as == ad ? -1 : (as < ad));
      dir_a = (ss == sd ? -1 : (ss < sd));

      // odd ~ true ~ increasing direction
      --ss, --as, --sd, --ad;
      ss<<=1, as<<=1, sd<<=1, ad<<=1;
      ss^=dir_s, as^=dir_a, sd^=dir_s, ad^=dir_a;
      ss += A<<1; sd += A<<1;// offset

      if(dir_s == -1 && dir_a == -1) continue;
      if(dir_s == -1) manhattan.add_or(as, as);
      else if(dir_a == -1) manhattan.add_or(ss, ss);
      else {
        // (ss and ad) or (as and sd) 
        // == (ss or as) and (ss or sd) and (ad or as) and (ad or sd)
        manhattan.add_or(ss, as);
        manhattan.add_or(ss, sd);
        manhattan.add_or(ad, as);
        manhattan.add_or(ad, sd);
      }
    }
    cout << (manhattan.possible() ? "Yes" : "No") << endl;
  }
}