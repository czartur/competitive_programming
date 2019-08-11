#include <bits/stdc++.h>
using namespace std;

//lazy implementation
//now you want to update a full range instead of an element inside it (usual update)
//build tree... lazy changes update and query functions
//example here is sum of a range

#define x 2*p
#define y 2*p+1
#define mid (l+r)/2

int st[4*N], lazy[4*N], v[N];


void push(int p, int l, int r){
  if(lazy[p]){
    st[p]+=lazy[p]*(r-l+1);
    if(l!=r) lazy[x]=lazy[y]+=lazy[p];
    lazy[p]=0;
  }
}
void update_range(int p, int l, int r, int i, int j, int val){
  push(p, l, r);
  if(l>=i && r<=j){
    st[p]+=val*(r-l+1);
    if(l!=r) lazy[x]=lazy[y]+=val;
  }
  if(l>j || r<i) return;
  update_range(x, l, mid, i, j, val), update_range(y, mid+1, r, i , j, val);
  st[p]=st[x]+st[y];
}

int query(int p, int l, int r, int i, int j){
  push(p, l, r);
  if(l>=i && r<=j) return st[p];
  if(l>j || r<i) return 0;
  return st[x] + st[y];
}

int main(){

}
