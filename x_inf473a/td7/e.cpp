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


void dfs(int cur, vector<int> &order, vector<bool> &seen, vector<vector<int>> &adj){
  seen[cur] = true;
  for(auto prox : adj[cur]){ 
    if(!seen[prox]) dfs(prox, order, seen, adj);
  }
  order.push_back(cur);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  cin.ignore();
  
  unordered_map<string, int> id;
  unordered_map<int, string> inv_id;
  int idn = -1;
  vector<vector<int>> adj(n);

  for(int i = 0; i < n; ++i){
    string line;
    getline(cin, line);
    stringstream ss(line);

    string s; ss >> s;
    s.pop_back();
    if(!id.count(s)) id[s] = ++idn, inv_id[idn] = s;
    int pai = id[s];
    while(ss >> s) {
      if(!id.count(s)) id[s] = ++idn, inv_id[idn] = s;
      int filho = id[s];
      adj[filho].push_back(pai);
    }
  }

  vector<int> order; 
  vector<bool> seen(n);

  string s; cin >> s;
  dfs(id[s], order, seen, adj);
  reverse(order.begin(), order.end());
  for(auto ii : order) cout << inv_id[ii] << endl;
}
