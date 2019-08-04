#include <bits/stdc++.h>
using namespace std;
//Merge Sort
//It does count inversions too

#define pb push_back

int inv=0;
vector <int> merge(vector <int>  v, int i, int j){
  vector <int> vl, vr, ans;
  if(i==j) {ans.pb(v[i-1]); return ans;}
  vl=merge(v, i, (i+j)/2), vr=merge(v, (i+j)/2+1, j);
  int l=0, r=0;
  while(l<vl.size() or r<vr.size()){
    if(vl[l]<=vr[r] || r==vr.size()) ans.pb(vl[l++]);
    else ans.pb(vr[r++]), inv++;
  }
  return ans;
}
int main(){
  int n, x;
  vector <int> v;
  scanf("%d", &n);
  while(n--) {scanf("%d", &x); v.pb(x);}
  v=merge(v, 1, v.size());
  n=v.size();
  while(n) {printf("%d ", v[v.size()-n--]);}
  printf("\n%d\n", inv);
}
