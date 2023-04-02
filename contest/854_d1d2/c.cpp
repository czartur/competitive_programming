#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =1e5+5;

void solve(){
  string s; cin >> s;
  map<char, int> cnt;
  for(auto c : s) cnt[c]++;
 
  string ls, rs;
  map<char,int>::iterator it;
  for(it = cnt.begin(); it != cnt.end(); it++){
    char letra = it->first;
    int qtd = it->second;
    // db(letra); db(qtd);
    while(qtd>=2){
      ls.pb(letra);
      rs.pb(letra);
      qtd-=2;
    }
    if(!qtd) continue;

    int idx = distance(it, cnt.end());
    if(idx == 1) ls.pb(letra);
    else if(idx == 2) {
      ++it;
      char last_letra = it->first;
      qtd = it->second;
      while(qtd>=2){
        ls.pb(last_letra); rs.pb(last_letra);
        qtd-=2;
      }
      if(qtd&1) rs.pb(last_letra);
      ls.pb(letra);
    }
    else {
      ls.pb(letra);
      while(++it != cnt.end()){
        qtd = it->second, letra = it->first;
        while(qtd--) rs.pb(letra);
      }
    }
    break;
  }
  reverse(ls.begin(), ls.end());
  std::cout << rs << ls << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--){
    solve();
  }
}
