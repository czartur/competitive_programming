#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  unordered_map<int, vector<int>> m;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    m[a].push_back(i);
  }

  while(q--){
    int l, r, p, k;
    cin >> l >> r >> p >> k;
    l--, r--;
    int ans = -2;
    int pos = lower_bound(m[p].begin(), m[p].end(), l)-m[p].begin();
    if(pos+k-1 < m[p].size() && r >=  m[p][k+pos-1]) ans = m[p][k+pos-1];
    cout << ans+1 << endl;
  }
}