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

int greed(int target, int start, vector<int>&coin){
  int pos = start;
  int ans = 0;
  while(pos >= 0){
    if(target > coin[pos]){
      ans += target/coin[pos];
      target %= coin[pos];
    }
    --pos;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> coin(n);
  for(auto& val : coin) cin >> val;

  bool canonical = 1;
  for(int target = *coin.rbegin(); target < coin[n-1] + coin[n-2]; ++target){
    for(int start = n-1; start >= 0; --start){
      if(greed(target, start, coin) < greed(target, n-1, coin)) canonical = 0;
    }
  }

  cout << (canonical ? "canonical" : "non-canonical") << endl;
}
