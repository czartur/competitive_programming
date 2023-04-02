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
    int n;  cin >> n;
    vector<vector<int>> p(n, vector<int>(n-1));
    for(int i=0; i<n; i++)
      for(int j=0; j<n-1; j++) cin >> p[i][j];

    // search lonely first
    int f = 0, novo = p[1][0];
    if(p[0][0] == p[1][0] || p[0][0] == p[2][0]){
      for(int i=1; i<n; i++){
        if(p[i][0] != p[0][0]) {f = i; novo = p[0][0];}
      }
    }

    cout << novo << " ";
    for(auto v : p[f]) cout << v << " ";
    cout << endl;

  }
}
