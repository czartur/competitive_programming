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

void bt(int r, int cur_k, int cur_value, pair<bool,bool> block, vector<pair<int,int>>&row, int k, int& ans){
  if(cur_k > k) return;

  if(r == row.size()){
    if(cur_k == k) ans = max(ans, cur_value);
    return;
  }

  if(cur_k < k){
    // block second
    if(!block.first){
      bt(r+1, cur_k+1, cur_value + row[r].first, make_pair(0,1), row, k, ans); 
    }
    // block first 
    if(!block.second){
      bt(r+1, cur_k+1, cur_value + row[r].second, make_pair(1,0), row, k, ans);
    }
  }
  // block nothing
  bt(r+1, cur_k, cur_value + row[r].first + row[r].second, make_pair(0,0), row, k, ans);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  while(cin >> n >> k){
    if(n == 0 && k == 0) return 0;
    vector<pair<int,int>> row(n);
    for(auto &p : row) cin >> p.first >> p.second;
    
    int ans = 0;
    bt(0, 0, 0, make_pair(0,0), row, k, ans);
    cout << ans << endl;
  }
}


// [3][k][n]

// [0,0][k][i] = 