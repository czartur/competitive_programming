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
  int num; cin >> num;
  vector<int> pos, neg;
  for(int i=0; i<num; ++i){
    int a; cin >> a;
    if(a >= 0) pos.push_back(a);
    else neg.push_back(a);
  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  reverse(pos.begin(), pos.end());

  vector<int> ans;
  int i = 0, j = 0, sum = 0;
  while(i < pos.size() || j < neg.size()){
    if(i == pos.size()) while(j < neg.size()) ans.push_back(neg[j++]);
    else if(j == neg.size()) while(i < pos.size()) ans.push_back(pos[i++]);
    else {
      if(sum > 0) sum += neg[j], ans.push_back(neg[j++]);
      else sum += pos[i], ans.push_back(pos[i++]);
    }
  }

  // kadane
  int cur = 0, glob = 0, maior = ans[0], menor = ans[0];
  for(int r=0; r<num; ++r){
    cur = max(ans[r], ans[r]+cur);
    glob = max(glob, cur);
    maior = max(maior, ans[r]);
    menor = min(menor, ans[r]);
  }

  if(glob >= maior - menor) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for(auto a : ans) cout << a << " ";
    cout << endl;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t; 
  while(t--){
    solve();
  }
}
