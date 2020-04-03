#include <bits/stdc++.h>
using namespace std;
//binary tricks
//first, definitions...
//"least" upper bound: menor elemento que é >= x
//"greatest" lower bound: maior elemento que é <= x
//exemplo: 10 20 20 20 30 (1-indexed)
//lower de x=20 é 2
//upper de x=20 é 4
#define mid ???
//for lower, define mid (l+r)/2
//for upper, define mid (l+r+1)/2

int v[N], n; //sorted array

int lowerb(int x){
  int l=1, r=n;
  while(l<r){
    if(x>v[mid]) l=mid+1;
    else r=mid;
  }
  return r;
}
int upperb(int x){
  int l=1, r=n;
  while(l<r){
    if(x<v[mid]) r=mid-1;
    else l=mid;
  }
  return r;
}
