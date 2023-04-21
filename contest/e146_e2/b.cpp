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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =1e5+5;

vector<int> div(ll x){
  vector<int> ans, rev;
  for(ll i=1; i*i<=x; ++i){
    if(x%i == 0){
      ans.push_back(i);
      if(i != x/i) rev.push_back(x/i);
    }
  }
  reverse(rev.begin(), rev.end());
  for(auto a : rev) ans.push_back(a);
  return ans;
}

void solve(){
  int b, a; cin >> b >> a;
  if(a > b) swap(a,b);

  vector<int> divb = div(b), diva = div(a);
  int da = diva[(diva.size())/2];
  int db = divb[(divb.size())/2];

  int ans = 0;
  ans += da-1 + a/da;
  db(db);
  db(b);
  db(da);
  ans += db-da + b/db;
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