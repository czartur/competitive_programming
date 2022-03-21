#include <bits/stdc++.h>
using namespace std;

//Segment Tree
//build O(n), update O(log(n)), query O(log(n))
//example base: sum of a segment

#define x 2*p
#define y 2*p+1
#define mid (l+r)/2

int st[4*N], v[N];

void build(int p, int l, int r){
  if(l==r) {st[p]=v[l]; return;}
  build(x, l, mid), build(y, mid+1, r);
  st[p]=st[x]+st[y];
}

void update(int p, int l, int r, int idx, int val){
  if(idx<l || idx > r) return;
  if(l==r) {st[p]+=val; return;}
  update(x, l, mid, idx, val), update(y, mid+1, r, idx, val);
  st[p]=st[x]+st[y];
}

int query(int p, int l, int r, int i, int j){
  if(l>=i && r<=j) return st[p];
  if(l>j || r<i) return 0; //here you must return sometihng neutral to the query result
  return query(x, l, mid, i, j) + query(y, mid+1, r, i, j); //it could min, max..
}
