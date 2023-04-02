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
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  for(int k=1; k<=n; k++){
    int l=1, r=k;
    while(l<r){
      int mid = (l+r+1)/2;
      if(a[k-mid]/mid < 1) r=mid-1;
      else l=mid;
    }
    cout << l << " ";
  }
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
