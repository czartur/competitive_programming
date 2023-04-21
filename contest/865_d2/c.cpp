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

void solve(){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto& val : a) cin >> val;

  ll cred = 0;
  for(int i = 0; i < n-1; i+=2){
    cred += a[i+1] - a[i];
  }
  if(n%2 == 0 && cred < 0) cout << "NO" << endl;
  else cout << "YES" << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}