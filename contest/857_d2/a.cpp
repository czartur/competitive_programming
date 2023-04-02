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
  int pos=0, neg=0;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    x > 0 ? pos++  : neg++;
  }
  int apos = pos, aneg = neg;
  int cur = 0;
  while(pos--) cout << ++cur << " ";
  while(neg--) cout << --cur << " ";
  cout << endl;

  pos = apos, neg = aneg;
  cur = 0;
  for(int i=0; i<neg; i++) cout << 1 << " " << 0 << " ";
  for(int i=0; i<pos-neg; i++) cout << ++cur << " ";
  cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
