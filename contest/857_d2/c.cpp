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
  vector <pair<int,int>> p(n);
  for(int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());

  // max from so on
  vector<int> grande(n);
  grande[n-1] = p[n-1].second;
  for(int i=n-2; i>=0; i--){
    grande[i] = max(grande[i+1], p[i].second);
  }

  set<int> seen;
  int ans = abs(p[0].first - grande[1]);
  seen.insert(p[0].second);
  for(int i=1; i<n; i++){
    int a = p[i].first, b = p[i].second;
    // db(a);
    if(i<n-1) ans = min(ans, abs(a - grande[i+1]));
    int lb = 0, ub = 0;
    if(seen.lower_bound(a) != seen.end()) lb = *seen.lower_bound(a);
    if(seen.upper_bound(a) != seen.end()) ub = *seen.upper_bound(a);
    if(i<n-1) lb = max(lb, grande[i+1]), ub = max(ub, grande[i+1]);
    if(lb) ans = min(ans, abs(lb-a));
    if(ub) ans = min(ans, abs(ub-a));
    seen.insert(b);
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
