#include<bits/stdc++.h>
using namespace std;

#define N 100
#define x 2*p
#define y 2*p+1
#define mid (l+r)/2

int st[4*N][11], lazy[4*N], charge[11];

void update(int p, int l, int r, int i, int j, int val){
  if(lazy[p]){
    for(int k=0; k<9; k++) charge[k]=st[p][k];
    for(int note=0; note<9; note++){
      st[p][note]=charge[(9+note-lazy[p])%9];
    }
    if(l!=r) lazy[y]=lazy[x]+=lazy[p];
    lazy[p]=0;
  }
  if(l>=i && r<=j) {
    for(int k=0; k<9; k++) charge[k]=st[p][k];
    for(int note=0; note<9; note++){
      st[p][note]=charge[(9+note-val)%9];
    }
    if(l!=r) lazy[x]=lazy[y]+=val;
    return;
  }
  if(l>j || r<i) return;
  update(x, l, mid, i, j, val), update(y, mid+1, r, i, j, val);
  for(int note=0; note<9; note++){
    st[p][note]=st[x][note]+st[y][note];
  }
}
int query(int note, int p, int l, int r, int i, int j){
  if(lazy[p]){
    for(int k=0; k<9; k++) charge[k]=st[p][k];
    for(int note=0; note<9; note++){
      st[p][note]=charge[(9+note-lazy[p])%9];
    }
    if(l!=r) lazy[y]=lazy[x]+=lazy[p];
    lazy[p]=0;
  }
  if(l>=i && r<=j) return st[p][note];
  if(l>j || r<i) return 0;
  return query(note, x, l, mid, i, j) + query(note, y, mid+1, r, i, j);
}

void build(int p, int l, int r){
  if(l==r) {st[p][1]=1; return;}
  build(x, l, mid), build(y, mid+1, r);
  st[p][1]=st[x][1]+st[y][1];
}

/*
void printst(int n){
  for(int j=0; j<9; j++){
    printf("%d: ", j);
    for(int k=1; k<=4*n; k++) printf("%d ", st[k][j]);
    printf("\n");
  }
  printf("\n");
  for(int j=1; j<4*n; j++) printf("%d ", lazy[j]);
  printf("\n");
}
*/

int main(){
  int n, q, a, b, f, m;
  scanf("%d%d", &n, &q);
  build(1, 1, n);
  //printst(n);
  for(int i=1; i<=q; i++){
    m=0;
    scanf("%d%d", &a, &b);
    a++, b++;
    for(int j=0; j<9; j++) {
      if(m<query(j, 1, 1, n, a, b)){
        m=query(j, 1, 1, n, a, b);
        f=j;
      }
    }
    update(1, 1, n, a, b, f);

    //printst(n);
  }

  for(int i=1; i<=n; i++){
    for(int j=0; j<9; j++) if(query(j, 1, 1, n, i, i)) printf("%d\n", j);
  }
}
