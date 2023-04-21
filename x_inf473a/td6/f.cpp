#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 100000;
const int N =1e5+5;

string formato(int ans){
  string resp;
  for(int i = 0; i < 4; ++i){
    resp.push_back(ans%10 + '0');
    ans = ans ? ans/10 : 0;
  }
  reverse(resp.begin(), resp.end());
  return resp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  cin.ignore();
  
  string goal = "welcome to code jam";
  string phrase;
  for(int tt = 1; tt <= t; ++tt){
    getline(cin, phrase);
    vector<vector<int>> dp(goal.size(), vector<int>(phrase.size()));
    
    dp[0][0] = goal[0] == phrase[0];
    for(int i  = 1; i < phrase.size(); ++i){
      dp[0][i] = ((goal[0] == phrase[i]) + dp[0][i-1])%MOD;
      for(int j = 1; j < goal.size(); ++j){
        dp[j][i] = dp[j][i-1];
        if(goal[j] == phrase[i]){
          dp[j][i] += dp[j-1][i-1];
        }
        dp[j][i] %= MOD;
      }
    }
    int ans = dp[goal.size()-1][phrase.size()-1];

    cout << "Case #" << tt << ": " << formato(ans) << endl;
  }



}
