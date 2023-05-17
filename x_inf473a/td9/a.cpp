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
  int l, s; cin >> l >> s;

  string base = string(l, '?');
  bool ok = 1;
  while(s--){
    int p; cin >> p; p--;
    string suf; cin >> suf;
    for(int i = 0; i < suf.size(); ++i){
      if(suf[i] != '*'){
        if(base[p+i] == '?') base[p+i] = suf[i];
        else if(base[p+i] != suf[i]) ok = 0;
      }
      else {
        p += l-(p+1)-(suf.size()-1);
      }
      // db(base);
    }
  }
  for(auto c : base) if(c == '?') ok = 0;
  if(ok) cout << base << endl;
  else cout << "IMPOSSIBLE" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    solve();
  }
}
