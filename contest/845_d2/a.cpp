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

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n; cin >> n;
    int prev; cin >> prev;
    prev = prev&1;
    int ans=0;
    for(int i=1; i<n; i++){
      int cur; cin >> cur;
      cur = cur&1;
      if(cur == prev) ans++;
      prev = cur;
    }
    cout << ans << endl;
  }
} 
