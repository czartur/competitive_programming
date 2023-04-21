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

struct Rob{
  int w, h;
};

int n, w, h, l, ans = INF;
void bt(int move, vector<Rob> &pos, string &mat, unordered_map<string, bool> &dp){
  if(dp[mat]) return;

  // test all robots 
  for(int i = 0; i < pos.size(); ++i){
    mat[pos[i].w*h + pos[i].h] = '.';
    // test 4 moves
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> w >> h >> l;

  string mat(w*h, '.');
  vector<Rob> pos(n);
  for(int i = 0; i < w; ++i){
    for(int j = 0; j < h; ++j){
      char c; cin >> c;
      cin >> mat[i*h +j];
      if(c >= '0' && c <= '9') pos[c-'0'-1] = {i,j};
    }
  }

  unordered_map<string, bool> dp;

}
