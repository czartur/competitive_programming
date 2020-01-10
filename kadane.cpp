#include <bits/stdc++.h>
using namespace std;


//Kadane's algorithm
//GOAL: Find maximum contiguous subarray
//HINT: store for each index the maximum subarray ending at them
int main(){
  int n, a[100];
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
  }

  int curr=0, glob=0;
  for(int r=1; r<=n; r++){
    curr=max(a[r], a[r]+curr);
    glob=max(glob, curr);
  }

  printf("%d\n", glob);
}
