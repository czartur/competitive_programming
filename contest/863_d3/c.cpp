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
  vector<int> a(n-1);
  for(auto &val : a) cin >> val;
  int put = 1; 
  for(int i=0; i<n-2; ++i){
    if(put) {
      cout << a[i] << " ";
      if(a[i]<a[i+1]) cout << (put = 0) << " ";
    } else {
      cout << min(a[i], a[i+1]) << " ";
    }
  }
  cout << a.back() << " ";
  if(put) cout << 0 << " ";
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}