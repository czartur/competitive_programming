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

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int N =5e5+5;


ll fexp(ll b, ll e){
  ll ans = 1;
  while(e){
    if(e&1) ans=(ans*b)%MOD;
    e/=2;
    b = (b*b)%MOD;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;

  ll sum = 0;
  ll zero = 0, q = 0;

  for(int i=0; i<s.size(); ++i){
    if(s[i] == '?') sum = (sum*2)%MOD;
    if(s[i] != '1'){
      ll add = (fexp(2, q)*(i-zero))%MOD;
      if(q) add = (MOD + add - (q*fexp(2, q-1))%MOD)%MOD;
      sum = (sum + add)%MOD;
      q += (s[i] == '?');
      zero += (s[i] == '0');
    }
  } 
  cout << sum << endl;
}
