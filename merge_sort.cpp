#include <bits/stdc++.h>
using namespace std;

// careful : overflow possible at 'inv' (use long long)
// i, j ~ 0 indexed

int inv=0; 
vector <int> merge(vector <int> &v, int i, int j){
  vector <int> vl, vr, ans;
  if(i==j) {ans.push_back(v[i]); return ans;}
  vl=merge(v, i, (i+j)/2), vr=merge(v, (i+j)/2+1, j);
  int l=0, r=0;
  while(l<vl.size() || r<vr.size()){
    if(r == vr.size() || (l<vl.size() && r<vr.size() && vl[l]<vr[r])) ans.push_back(vl[l++]);
    else ans.push_back(vr[r++]), inv+=vl.size() - l;
  }
  return ans;
}