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
  string s; cin >> s;
  vector<int> mp(30, -1);
  mp[s[0]-'a'] = 0;
  bool ok = 1;
  for(int i=1; i<n; i++){
    if(mp[s[i]-'a'] == mp[s[i-1]-'a']) ok = 0;
    else mp[s[i]-'a'] = mp[s[i-1]-'a']^1;
  }
  cout << (ok ? "yes" : "no") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
