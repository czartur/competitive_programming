#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, q, g;
ll gcd(ll a, ll b){
  return b ? gcd(b, a%b) : a;
}

ll group(int a, ll b){
  if(a==1){
    return (b+(n/g)-1)/(n/g);
  }
  return (b+(m/g)-1)/(m/g);
}

int main(){
  scanf("%lld%lld%lld", &n, &m, &q);
  g=gcd(n,m);
  ll sx, sy, ex, ey;
  for(int i=1; i<=q; i++){
    scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
    group(sx, sy)==group(ex,ey) ? printf("Yes\n") : printf("No\n");
  }
}
