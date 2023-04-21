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
  vector<ll> a(n), b(n);
  for(auto& val : a) cin >> val;
  for(auto& val : b) cin >> val;

  ll area[3] = {0,0,0};
  ll row[3] = {0,0,0};
  for(int i = 0; i < n; ++i){
    row[i%3] +=  a[i];
  }
  for(int j = 0; j < n; ++j){
    for(int i = 0; i < 3; ++i){
      area[(i+j+2)%3] += row[i]*b[j];
    }
  }

  cout << area[0] << " " << area[1] << " " << area[2] << endl;
}
