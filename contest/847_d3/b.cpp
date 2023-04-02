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

  int t; cin >> t;
  while(t--){
    int n, s, r;
    cin >> n >> s >> r;
    

    vi ans;
    n--;
    int round = (r+n-1)/n;
    for(int i=0; i<n; i++) ans.pb(round);
    //cout << r-(n-1)*round << endl;
    for(int i=0; i<round*n-r; i++) ans[i]--;
    ans.pb(s-r);
    
    for(auto a : ans) cout << a << " ";
    cout << endl;
  }
}
