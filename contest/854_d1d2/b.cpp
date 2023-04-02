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

int fin(vector <int> &a){
  int aux = INF;
  int ans = 0;
  for(int i=0; i<a.size(); i++){
    if(aux > a[i]) aux = a[i], ans = i;
  }
  return ans;
}

int fax(vector<int> &a){
  int aux = -1;
  int ans =  0;
  for(int i=0; i<a.size(); i++){
    if(aux < a[i]) aux = a[i], ans = i;
  }
  return ans;
}

void solve(){
  int n; cin >> n;
  if(n == 0) {
    cout << 0 << endl;
    return;
  }
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];

  if(a[fin(a)] == 1 && a[fax(a)] > 1){
    cout << -1 << endl;
    return;
  }
  int l, r;
  vector<pair<int,int>> pares;
  // int MAX_IT = 0;
  while(a[l=fin(a)] < a[r=fax(a)]){
    // db(a[l]); db(a[r]);
    a[r] = (a[r]+a[l]-1)/a[l];
    pares.push_back({r,l});
  }
  cout << pares.size() << endl;
  for(auto p : pares){
    cout << 1+p.st << " " << 1+p.nd << endl;
  }
//   for(auto x : a) cout << x << " ";
//   cout << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    solve();
  }
}
