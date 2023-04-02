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
  string a,b;
  cin >> a >> b;

  string ans;
  // test ends
  if(a[0] == b[0]) ans.pb(a[0]), ans+='*';
  else if(a.back() == b.back()) ans+='*', ans+=a.back(); 
  else {
    // test two in the middle
    for(int i=0; i<a.size()-1; i++){
      if(b.find(a.substr(i,2)) == string::npos) continue;
      ans+="*"+a.substr(i,2)+"*";
      break;
    }
  }
  if(ans.empty()) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    cout << ans << endl;
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
