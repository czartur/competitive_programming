#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5;


void solve(int tt){
  int n; cin >> n;
  vector<int> s(n);
  for(auto& val : s) cin >> val;
  vector<int> sum(n*1e5 + 1);

  int s1=-1, s2=-1;
  for(int set = 1; set < (1<<n); ++set){
    int cur_sum = 0;
    for(int i = 0, b = 1; i < n; b<<=1, ++i){
      if(b&set) cur_sum += s[i];
    }
    if(sum[cur_sum]) s1 = sum[cur_sum], s2 = set;
    else sum[cur_sum] = set;
  }

  cout << "Case #" << tt << ":" << endl;  
  if(~s1){
    for(int i = 0, b = 1; i < n; b<<=1, ++i){
      if(b&s1) cout << s[i] << " ";
    }
    cout << endl;
    for(int i = 0, b = 1; i < n; b<<=1, ++i){
      if(b&s2) cout << s[i] << " ";
    }
    cout << endl;
  }
  else {
    cout << "impossible" << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  for(int tt = 1; tt <= t; ++tt){
    solve(tt);
  }
}

