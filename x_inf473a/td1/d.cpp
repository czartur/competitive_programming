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

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int N =1e5+5;

void solve(int n){
  stack<pair<ll,ll>> s;

  ll ans = 0;
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    ll lp = i; 
    while(!s.empty() && s.top().st > x){
      ll h = s.top().st, p = s.top().nd;
      ans = max(ans, h*(i-p));
      s.pop();
      lp = p;
    }
    s.push(mp(x, lp)) ; 
  }

  ll r = 0;
  if(!s.empty()) r = s.top().nd+1;
  while(!s.empty()){
    ll h = s.top().st, p = s.top().nd;
    ans = max(ans, h*(r-p));
    s.pop();
  }
  cout << ans << endl; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(cin >> n){
    if(n==0) return 0;
    solve(n);
  }
}
