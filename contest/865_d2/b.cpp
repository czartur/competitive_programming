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
  int p=1, q=2*n-2;
  vector<pair<int,int>> ans;
  for(int i=1; i<n; ++i){
    if(i&1) ans.push_back({p++, p++});
    else ans.push_back({q-1, q}), q-=2;
  }
  cout << 2*n << " ";
  for(auto a : ans) cout << a.first << " ";
  cout << endl;
  for(auto a : ans) cout << a.second << " ";
  cout << 2*n-1 << endl;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}