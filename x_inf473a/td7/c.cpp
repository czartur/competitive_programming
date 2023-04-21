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


struct edge{
  int person, from, day;
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> id;
  int n, m, d; cin >> n >> m >> d;

  // change later
  vector<int> skept(n);
  vector<vector<int>> adj(n);

  for(int i = 0; i < n; ++i){
    string person; int t;
    cin >> person >> t;
    id[person] = i;
    skept[i] = t;
  }

  while(m--){
    string a, b; cin >> a >> b;
    adj[id[a]].push_back(id[b]);
    adj[id[b]].push_back(id[a]);
  }

  string gossip; cin >> gossip;

  // bfs
  vector<int> hear(n);
  vector<bool> process(n);
  queue<edge> q; q.push({id[gossip], -1, 1});
  while(!q.empty()){
    auto [person, from, days] = q.front(); q.pop();
    // cout << person << " " << days << endl;
    process[person] = true;
    for(auto next : adj[person]){
      if(days <= d && next != from && !process[next]) ++hear[next];
      if(!process[next] && hear[next] == skept[next]) q.push(edge{next, person, days+1});
    }
  }

  int ans = 0;
  for(auto h : hear) {
    ans += h>0;
  }
  cout << ans << endl;
}
