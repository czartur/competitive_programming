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
const int mod = 1e9+7;
const int N =1e5+5;

ll inv=0;
vector <int> merge(vector <int> &v, int i, int j){
  vector <int> vl, vr, ans;
  if(i==j) {ans.pb(v[i]); return ans;}
  vl=merge(v, i, (i+j)/2), vr=merge(v, (i+j)/2+1, j);
  int l=0, r=0;
  while(l<vl.size() || r<vr.size()){
    if(r == vr.size() || (l<vl.size() && r<vr.size() && vl[l]<vr[r])) ans.pb(vl[l++]);
    else ans.pb(vr[r++]), inv+=(ll)vl.size() - l;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--){
    inv=0;
    int n; cin >> n;
    vi v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    merge(v, 0, n-1);
    cout << inv << endl; 
  }
}
