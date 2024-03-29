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


int luck(int x){
  int maxd = -1, mind = 10;
  while(x){
    maxd = max(maxd, x%10);
    mind = min(mind, x%10);
    x/=10;
  }
  return maxd-mind;
}
void solve(){
  int a, b;
  cin >> a >> b;
  int ans = a;
  for(int i=a; i<=b; ++i){
    if(luck(i) > luck(ans)) ans = i;
    if(luck(i) == 9) break;
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
