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

string op(int i, int j, string &s){
  string ans = s;
  for(int ii = 0; ii < 3; ++ii){
    ans[j + 3*ii] = (s[j + 3*ii]-'0' + 1)%4 + '0';
  }
  for(int jj = 0; jj < 3; ++jj){
    ans[jj + 3*i] = (s[jj + 3*i]-'0' + 1)%4 + '0';
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string toy = "012345678";
  for(auto& c : toy) cin >> c;

  map<string, int> id;  
  id[toy] = 0;

  queue<pair<string,int>> q;

  q.push({toy, 0}); 
  while(!q.empty()){
    auto [cur, steps] = q.front();
    q.pop();

    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        string next = op(i, j, cur);
        if(!id.count(next)){
          id[next] = steps+1;
          q.push({next, steps+1});
        }
      }
    }
  }

  string gg = "000000000";
  if(!id.count(gg)) id[gg] = -1;
  cout << id[gg] << endl;
}
