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

const string cat = "meow";
void solve(){
  int n; cin >> n;
  string s; cin >> s;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  bool ok = s[0]=='m' ;
  int j = 0;
  for(int i=1; i<n; i++){
    if(s[i] == s[i-1]) continue;
    if(++j >= cat.size()) ok = 0;
    else if(s[i] != cat[j]) ok = 0;
  }
  if(ok && j==cat.size()-1) cout << "Yes" << endl;
  else cout <<  "No" << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
