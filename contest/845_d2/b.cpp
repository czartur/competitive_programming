#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const ll mod = 1e9+7;
const int N = 1e5+5;
ll fat[N];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  fat[0]=1;
  for(ll i=1; i<N; i++) fat[i]=(fat[i-1]*i)%mod;

  while(t--){
    ll n; cin >> n;
    cout << (fat[n]*((n*(n-1))%mod))%mod << endl;
  }
}
