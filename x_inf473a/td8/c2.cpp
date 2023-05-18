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

struct node {
  map<char, node*> c;
  int size = 0; // stores how many leafs from here *(allows repetition)
  bool flag = false; // if node represents the end of a word

  template <typename It>
  void insert(It first, It last){
    if (first == last){
      flag = true;
      return;
    }
    if(!c[*first]) c[*first] = new node;
    ++c[*first]->size;
    c[*first]->insert(first+1, last);
  }

  template <typename It>
  node* search(It first, It last){
    if(first == last) return this;
    if(!c.count(*first)) return nullptr; // not found
    return c[*first]->search(first+1, last);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  node* trie = new node;

  int n; cin >> n;
  while(n--){
    string s; cin >> s;
    node* pos = trie->search(s.begin(), s.end());
    if(pos) cout << pos->size << endl;
    else cout << 0 << endl;
    trie->insert(s.begin(), s.end());
  }
}
