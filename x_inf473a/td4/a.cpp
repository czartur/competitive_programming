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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<int> t(n), l(m);
  for(auto & val : t) cin >> val;
  for(auto & val : l) cin >> val;

  sort(t.begin(), t.end());
  sort(l.begin(), l.end());
  
  int ans = 0;
  for(int ll=m-1, tt=n-1; ll>=0; --ll, --tt){
    while(tt>=0 && t[tt] > l[ll]) --tt;
    if(tt < 0) break;
    ans++;
  }
  cout << ans << endl;
}