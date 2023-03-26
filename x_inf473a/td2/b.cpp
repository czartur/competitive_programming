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


bool prime(ll n){
  for(ll i=2; i*i<=n; ++i){
    if(n%i == 0) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(1){
    ll n; cin >> n;
    if(n == 0) return 0;

    ll ans = 2*n+1;
    while(!prime(ans))++ans;
      
    if(!prime(n)) cout << ans << " (" << n << " is not prime)" << endl;
    else cout << ans << endl;
  }
}
