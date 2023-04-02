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

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vi a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int cur=INF;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cur = min(cur, gcd(a[i], a[j]));
        }
    }

    if(cur > 2) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}
