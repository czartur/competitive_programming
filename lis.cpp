#include <bits/stdc++.h>
using namespace std;
//Longest increasing subsequence (LIS)
//Ideia das pilhas com vector

int main(){
  int n, a;
  vector <int> v;
  vector <int>::iterator it;
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a);
    it=lower_bound(v.begin(), v.end(), a);
    if(it==v.end()) v.push_back(a);
    else *it=a;
  }
  printf("L.I.S is %d", v.size());
}
