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
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =1e5+5;

void solve(){
  int n; cin >> n;

  vector<int> ans;
  // cout << "new _ test" << endl;
  while(n > 1){ 
    if((n&1) == 0) break;
    int op1 = (n-1)/2, op2 = (n+1)/2;
    if(op1&1){
      n = op1;
      ans.push_back(2);
    }
    else if(op2&1){
      n = op2;
      ans.push_back(1);
    }
  }

  if(n > 1 || ans.size() > 40) cout << -1 << endl;
  else {
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << " ";
    cout << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
