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

void solve(){
  int r, c; cin >> r >> c;

  int p, q, s, i, j;
  cout << "?" << " " << 1 << " " << 1 << endl;
  cout.flush() ;
  cin >> p;
  if(p+1 > c){
    i = p+1;
    cout << "?" << " " << i << " " << 1 << endl;
    cout.flush();
    cin >> j;
    ++j;
  } else if(p+1 > r){
    j = p+1;
    cout << "?" << " " << 1 << " " << j << endl;
    cout.flush();
    cin >> i;
    ++i;
  }
  else {
    cout << "?" << " " << p+1 << " " << p+1 << endl;
    cout.flush(); 
    cin >> q;
    i=p+1, j = p+1-q;
    cout << "?" << " " << i << " " << j << endl;
    cout.flush();
    cin >> s;  
    if(s) swap(i,j);
  }
  cout << "!" << " " << i << " " << j << endl;
  cout.flush();
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t; 
  while(t--){
    solve();
  }
}