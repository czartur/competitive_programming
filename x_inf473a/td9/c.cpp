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


void solve(){
  int k, w; cin >> k >> w;
  vector<string> words(w);
  for(auto& val : words) cin >> val;

  // 100*100*100
  int ans = k*w;
  for(int i = 1; i < w; ++i){
    int sub = 0;
    for(int sp = k-1; sp >= 0; --sp){
      bool ok = 1;
      for(int j = sp; j < k; ++j){
        if(words[i-1][j] != words[i][j-sp]) ok = 0;
      } 
      if(ok) sub = k-sp;
    }
    ans -= sub;
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    solve();
  }
}
