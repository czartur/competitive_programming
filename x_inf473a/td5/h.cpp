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

int codify(vector<int> coef, int l){
  sort(coef.begin(), coef.end());
  int ans=0, f=1;
  for(auto& val : coef) ans+=val*f, f*=l;
  return ans;
}

int count(int i, vector<int> &lane, vector<int>&dp, vector<int> &car, int l){
  int h = codify(lane, l);
  if(i == car.size()) return 0;
  if(~dp[h]) return dp[h];
  int ans = 0;
  for(int p=0; p<4; ++p){
    if(lane[p] + car[i]+1 >= l) continue;
    lane[p] += car[i]+1;
    ans = max(ans, 1+count(i+1, lane, dp, car, l));
    lane[p] -= car[i]+1;
  }
  return dp[h] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l; cin >> n >> l;
  vector<int> car(n), lane(4);
  for(auto& val : car) cin >> val;
  l+=2; vector<int> dp(4*l*l*l*l, -1);
  cout << count(0, lane, dp, car, l) << endl;
}
