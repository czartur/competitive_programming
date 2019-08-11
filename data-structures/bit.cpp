#include <bits/stdc++.h>
using namespace std;
//Binary indexed tree(BIT)
//Example: sum of a range
//p&(-p) is the last bit of the set
//to take a range (l,r) you need to do query operation two times...

int n, bit[100005];
void add(int idx, int val){
  for(int p=idx; p<=n; p+=p&(-p)) bit[p]+=val;
}
int query(int idx){
  int ans=0;
  for(int p=idx; p>0; p-=p&(-p)) ans+=bit[p];
  return ans;
}
