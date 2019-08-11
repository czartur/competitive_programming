#include <bits/stdc++.h>
using namespace std;
//Disjoint Set Union

//Find function returns the representative of a Set
//"Path-compression" is used here, the strategy is
//every element of a set is connected to the representative

//Union function joins two sets (by its representatives)
//"Union by rank" is used here, the strategy is
//plug smaller set into the bigger on

//building: each element starts like an individual set
//and connected to itself (the element is your own representative)

int par[N], sz[N]; //pai e tamanho do set

int find(int a){
  if(par[a]==a) return a;
  return par[a]=find(par[a]);
}

void union(int a, int b){
  a=find(a), b=find(b);
  if(sz[a]<sz[b]) swap(a,b);
  par[a]=b;
  sz[b]+=sz[a];
}
