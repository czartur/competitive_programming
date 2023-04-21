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

  int m; cin >> m;
  vector<int> v(m);
  set<int> leafs;
  map<int,int> deg;
  for(int i = 1; i <= m+1; ++i) leafs.insert(i);

  for(auto& val : v) {
    cin >> val;
    deg[val]++;
    leafs.erase(val);
  }

  vector<int> ans;
  bool ok = v.back() == m+1;
  for(auto cur : v){
    if(leafs.empty()){ ok = false; break; }

    ans.push_back(*leafs.begin());
    leafs.erase(leafs.begin());

    if(--deg[cur] == 0) leafs.insert(cur);
  }

  if(ok) {
    for(auto val : ans) cout << val << endl;
  } 
  else cout << "Error" << endl;
}
