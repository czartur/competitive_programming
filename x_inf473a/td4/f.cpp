#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int N =1e5+5;

class Trie{
  vector<vector<int>> nodes;
  vector<vector<bool>> end;
  int size;

public:
  // size_max --> max number of nodes
  Trie(int size_max): size{0}{
    nodes.resize(size_max);
    end.resize(size_max);
    for(int i=0; i<size_max; ++i) nodes[i].resize(26), end[i].resize(26);
  }

  void add(const string &s){
    int u = 0;
    char last;
    for(int i=0; i<s.size(); ++i) {
      char c = s[i]-'a';
      if(!nodes[u][c]) nodes[u][c] = ++size;
      if(i == s.size()-1) end[u][c] = 1;
      u = nodes[u][c]; 
    }
  }

  int prox(int u, char c){
    return nodes[u][c];
  }

  bool has(int u, char c){
    return end[u][c];
  }
};

void solve(Trie& trie, string &message){
  // build intervals
  vector<pair<int,int>> intervals;
  int m = message.size()-(*message.rbegin() == '|');
  // int m = message.size() - 1;
  for(int i=0; i<m; ++i){
    int u = 0;
    // cout << "==== pos : " << i << endl;
    for(int j=i; j<min(i+10, m); ++j){
      char c = message[j]-'a';
      // cout << (char) (c + 'a') << " " << trie.prox(u,c) << " " << trie.has(u,c) << endl;
      if(trie.has(u,c)) intervals.push_back({j, i});
      if(!trie.prox(u,c)) break;
      u = trie.prox(u,c);
    }
  }

  sort(intervals.begin(), intervals.end());
  int last = -1, ans = 0;
  for(auto [j, i] : intervals){
    if(i <= last) continue;
    last = j;
    ++ans;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Trie trie(10*100+1);
  while(true){
    string cur; cin >> cur;
    if(cur == "#") break;
    trie.add(cur);
  }

  string message;
  while(true){
    string cur; cin >> cur;
    message += cur;
    if(message == "#") break;
    if(*message.rbegin() != '|') continue;
    solve(trie, message);
    message.clear();
  }
}
