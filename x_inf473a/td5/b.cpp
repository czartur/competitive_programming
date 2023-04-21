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

  int n; cin >> n;
  double fee, a=0, l=100; cin >> fee;
  vector<double> price(n);
  for(auto& val : price) cin >> val;

  for(auto p : price){
    l = max(l, a*p-fee);
    a = max(a, (l-fee)/p);
  }
  cout << setprecision(6) << fixed << l << endl;
}
