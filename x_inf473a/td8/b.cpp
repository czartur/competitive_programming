#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e7;

int memo[N];
bool vis[N];

int solve(bitset<23> &b){
  int qtd = b.to_ulong();
  if(~memo[qtd]) return memo[qtd];
  if(vis[qtd]) return 23;
  vis[qtd] = 1;

  int ans = 23;
  for(int i = 1; i+1<23; ++i){
    if(b[i-1]&b[i]&(b[i+1]^1)){
      b[i-1] = 0;
      b[i] = 0;
      b[i+1] = 1;
      ans = min(ans, solve(b));
      b[i-1] = 1;
      b[i] = 1;
      b[i+1] = 0;
    }
    else if((b[i-1]^1)&b[i]&b[i+1]){
      b[i-1] = 1;
      b[i] = 0; 
      b[i+1] = 0;
      ans = min(ans, solve(b));
      b[i-1] = 0;
      b[i] = 1;
      b[i+1] = 1;
    }
  }

  return memo[qtd] = min(ans, (int) b.count());
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(memo, -1, sizeof(memo));

  int n; cin >> n;
  while(n--){
    string line; cin >> line;

    bitset<23> b;
    for(int i = 0;  i < 23; ++i) b[i] = (line[i] == 'o');
    cout << solve(b) << endl;
  }
}