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
const ll MOD = 998244353;
const int N = 1e5+5;

void solve(){
  ll l, r; cin >> l >> r;

  // possible paths :  i*2^a*3*2^b or i*2^a  <= r

  // max size
  ll d=0; while(l*(1<<++d) <= r);

  // amount of numbers in each path
  ll com3 = max(0LL, 2*r/(3*(1<<(d-1)))-l+1), sem3 = r/(1<<(d-1)) - l+1;

  // count
  ll total=0;
  total += sem3%MOD;
  total += (com3*(d-1))%MOD;

  cout << d << " " << total << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    solve();
  }
}
