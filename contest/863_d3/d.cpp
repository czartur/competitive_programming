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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =1e5+5;

int fib[50];
bool can(int x, int y, int fh, int fw){
  if(fh + fw == 3) return true;
  if(fh > fw){
    if(x <= fib[fw] && x > fib[fh]-fib[fw]) return false;
    if(x > fib[fw]) x-=fib[fw];
    return can(x, y, fh-2, fw);
  }
  
  if(fw > fh){
    if(y <= fib[fh] && y > fib[fw]-fib[fh]) return false;
    if(y > fib[fh]) y-=fib[fh];
    return can(x, y, fh, fw-2);
  }
}

void solve(){
  int n, x, y; cin >> n >> x >> y;
  fib[0] = fib[1] = 1;
  for(int i=2; i<50; ++i){
    fib[i] = fib[i-1]+fib[i-2];
  }

  cout << (can(x, y, n, n+1) ? "YES" : "NO") << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}