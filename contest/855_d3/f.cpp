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
const int M =1<<26;

void solve(){
  int n; cin >> n;
  ll sum = 0;
  vector<int> conta(M);
  vector<int> tenho(n), odd(n);
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(auto c : s) tenho[i]|=1<<c-'a', odd[i]^=1<<c-'a';
  } 
  for(int bit=1; bit<M; bit<<=1){
    // count only when bit not present in both
    for(int i=0; i<n; i++) if(!(tenho[i]&bit)){
      conta[odd[i]]++;
      sum += conta[(odd[i]|bit)^(M-1)];
    }
    // reset count
    for(int i=0; i<n; i++) conta[odd[i]] = 0;
  }
  cout << sum << endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t=1;  
  while(t--){
    solve();
  }
}
