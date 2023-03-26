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

  int n;
  while(cin >> n){
    if(n == 0) return 0;
    char c; cin >> c;
    vector<int> p(n);
    for(int i=0; i<n; i++){
      int val; cin >> val;
      p[val] = i;
    }

    bool ok = 0;
    for(int i=0; i<n; i++){
      for(int c=1; i-c>=0 && i+c<n; c++){
        ok |= p[i+c] > p[i] && p[i-c] < p[i];
        ok |= p[i-c] > p[i] && p[i+c] < p[i];
      }
    }
    cout << (!ok ? "yes" : "no") << endl; 
  }
}
