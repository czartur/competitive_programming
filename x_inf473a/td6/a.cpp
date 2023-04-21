#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w, n; cin >> w >> n;
  ll area = 0;
  for(int i = 0; i < n; ++i){
    ll ww, ll; cin >> ww >> ll;
    area += ww*ll;
  }
  cout << area / w << endl;
}
