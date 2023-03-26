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

  int n; cin >> n;
  unordered_map<string, vector<int>> mapa;
  int id = -1;
  for(int i=0; i<n; i++){
    string s; int y;
    cin >> s >> y;
    mapa[s].push_back(y);
  }
  for(auto& v : mapa) sort(v.second.begin(), v.second.end());

  int q; cin >> q;
  for(int i=0; i<q; i++){
    string s; int vez;
    cin >> s >> vez;
    cout << mapa[s][vez-1] << endl;
  }
}
