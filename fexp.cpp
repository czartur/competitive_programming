
// fast exponentiation

ll fexp(ll b, ll e){
  ll ans=1;
  while(e){
    if(e&1) ans*=b;
    b*=b;
    e/=2;
  }
  return ans;
}
