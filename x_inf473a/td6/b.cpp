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

  int n, m; cin >> n >> m;
  vector<ll> tin(n), tout(m);
  for(auto& val : tin) cin >> val;
  for(auto& val : tout) cin >> val;

  map<ll, int> dif;
  for(auto in : tin){
    for(auto out : tout){
      if(out - in >= 0) ++dif[out-in];
    } 
  }

  ll ans = 0, freq = 0;
  for(auto p : dif){
    if(p.second > freq) freq = p.second, ans = p.first;
  }

  cout << ans << endl;
}
