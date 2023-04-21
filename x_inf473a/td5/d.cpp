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


string recovery(int l, int w, vector<vector<int>> &dp){
  if(l==0) return string();
  for(int c=1; c<=26; ++c){
    if(dp[l-1][w-c]){
      string s = recovery(l-1, w-c, dp);
      s.push_back((char) (c+'a'-1));
      return s;
    }
  }
  return "impossible";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int L, W; cin >> L >> W;

  vector<vector<int>> dp(L+1, vector<int>(W+1));

  dp[0][0] = 1;
  for(int l=1; l<=L; ++l){
    for(int w=1; w<=W; ++w){
      for(int c=1; c<=26; ++c){
        if(w-c >=0) dp[l][w] |= dp[l-1][w-c];
      }
    }
  }
  
  if(!dp[L][W]) cout << "impossible" << endl;
  else cout << recovery(L, W, dp) << endl;
}
