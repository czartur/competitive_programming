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
  int n, d; cin >> n >> d;
  vector<int> ans;
  for(int i=0; i<n; ++i){
    char c; cin >> c;
    c-='0';
    if(c < d) ans.push_back(d), d=-1;
    ans.push_back(c);
  }
  if(~d) ans.push_back(d);
  for(auto c : ans) cout << c;
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