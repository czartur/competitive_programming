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

class Trie{
  vector<vector<int>> nodes;
  vector<vector<int>> path;
  int size;

public:
  // size_max --> max number of nodes
  Trie(int size_max): size{0}{
    nodes.resize(size_max);
    path.resize(size_max);
    for(int i=0; i<size_max; ++i) nodes[i].resize(26), path[i].resize(26);
  }

  int add(const string &s){
    int u = 0;
    int ans = 0;
    for(int i=0; i<s.size(); ++i) {
      char c = s[i]-'a';
      if(i == s.size() -1) ans = path[u][c];
      if(!nodes[u][c]) {
        nodes[u][c] = ++size;
      }
      ++path[u][c];
      u = nodes[u][c]; 
    }
    return ans; 
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  Trie trie(32*n+1);
  while(n--){
    string word; cin >> word; 
    cout << trie.add(word) << endl;
  }
}