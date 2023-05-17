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


int kmp(string& word, string &data, vector<int> &considered){
  int ans = 0;
  vector<int> pref(t.size());
  pref[0] = 0;
  for(int i = 1; i < t.size(); ++i){
    int sz = pref[i-1];
    while(t[i] != t[sz] && sz > 0){
      sz = t[sz-1];
    }
    pref[i] = sz + (t[i] == t[sz]);
    ans = max(ans, pref[i]);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string data;
  vector<int> considered;
  for(int i = 0; i < n; ++i){
    string word; cin >> word;
    data += word;
    for(int j = 0; j < word.size(); ++j) considered.push_back(i+1);
  }

  int q; cin >> q;
  string query;
  while(q--){
    cin >> query;
    int ans = 0;
    int matching = kmp(data + "#" + query);
    if(matching == query.size()) break;
    cout << ans << endl;
  }

  // kmp("robot#robi");
}
