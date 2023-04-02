#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define endl '\n'

#define db(x) cerr << #x << " == " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int N = 1e5+5;
vector<ll> divi[N]; 

void init(){
  for(int i=1; i<N; i++){
    for(int j = i; j < N; j+=i){
      divi[j].pb(i);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  init();
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    unordered_map<int, int> hash;
    int ans = inf;
    
    for(int l=0, r=0; l<n; l++){
      for(auto d : divi[a[l]]) if(d<=m) hash[d]++;
      while(hash.size() == m && r<=l){
        ans = min(ans, a[l]-a[r]);
        for(auto d : divi[a[r]])
          if(d<=m && --hash[d] == 0) hash.erase(d);
        r++;
      }
    }

    if(ans == inf) ans = -1;
    cout << ans << endl;
  }
}
