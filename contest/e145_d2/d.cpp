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

const ll troca = 1e12, tira = 1e12+1;

void solve(){
  string s; cin >> s;
  ll n = s.size();
  ll l1 = 0, r0 = count(s.begin(), s.end(), '0');
  ll ans = LINF, cur;
  if(n == 1) ans = 0;
  for(int i=0; i<n-1; ++i){
    // try i and i+1
    r0 -= s[i] == '0';

    ll k = r0 - (s[i+1] == '0') + l1;
    cur = k*tira + (s[i] > s[i+1])*troca;
    ans = min(ans, cur);
    
    l1 += s[i] == '1';
  }
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
