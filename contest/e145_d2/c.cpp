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

const ll cost = 1e12;

vector<int> build(int n, int k){
  vector<int> ans;
  if(k == 0){
    for(int i=0; i<n; ++i) ans.push_back(-1);
    return ans;
  }
  
  if(n == 1) return vector<int>{1-2*(k==0)};

  if(k < n){
    for(int i=0; i<k-1; ++i) ans.push_back(-1);
    ans.push_back(k);
    ans.push_back(-k-1);
    while(ans.size() < n) ans.push_back(-1);
    return ans;
  }

  ans = build(n-1, k-n);
  ans.push_back(1000);
  return ans;
}
void solve(){
  int n, k; cin >> n >> k;
  vector<int> ans = build(n,k);
  for(auto v : ans) cout << v << " ";
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
