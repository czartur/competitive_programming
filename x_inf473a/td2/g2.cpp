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

const int cmp = 1e4;
bool prime(int x){
  if(x == 1) return false;
  for(int i=2; i<=cmp && i*i<=x; i++){
    if(x%i == 0) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  int cnt = 0;
  for(int i=1; i<=n; i++) cnt += prime(i);
  cout << cnt << endl;
  for(int i=0; i<q; i++){
    int x; cin >> x;
    cout << prime(x) << endl;
  }
}
