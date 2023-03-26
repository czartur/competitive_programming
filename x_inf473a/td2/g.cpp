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

  int n, q, cnt = 0;
  cin >> n >> q;
  vector<bool> cmp(n+1);
  cmp[1] = 1;
  for(ll i=2; i<=n; ++i) if(!cmp[i]){
    ++cnt;
    for(ll j=2*i; j<=n; j+=i){
      cmp[j] = 1;
    }
  }

  cout << cnt << endl;
  for(int i=0; i<q; i++){
    int x; cin >> x;
    if(cmp[x]) cout << 0 << endl;
    else cout << 1 << endl;
  }
}
