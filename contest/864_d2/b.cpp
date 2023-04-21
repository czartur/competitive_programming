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
  int n, k; cin >> n >> k;
  vector<vector<int>> g(n, vector<int>(n));
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      cin >> g[i][j];
    }
  }

  int dif = 0, mid = 0, free = n&1;
  for(int i=0; i<n/2; ++i){
    for(int j=0; j<n; ++j){
      dif += (g[i][j] != g[n-i-1][n-j-1]);
    }
  }
  if(n&1){
    int i = n/2;
    for(int j=0; j<n; ++j){
      mid += (g[i][j] != g[n-i-1][n-j-1]);
    }
    mid/=2;
  }

  bool ok = 1;
  dif += mid;
  dif = min(dif, n*n-dif);
  if(k < dif ) ok = 0;
  else if(((k-dif)%2) && !free) ok = 0;
  cout << (ok ? "YES" :  "NO") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}