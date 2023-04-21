
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl

int cod(vector<int> &coef, int l){
    int f=1, ans = 0;
    for(auto val : coef){
        ans += val*f;
        f*=l;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector <int> q(n), psum(n);
    for(auto& val : q) cin >> val;
    for(int i=0, sum=0; i<n; ++i){
      sum += q[i]+1;
      psum[i] = sum;
    }

    l+=2;
    int L = l*l*l*l;
    vector <int> dp(L), aux(L);
    int ans = 0;
    dp[0] = 1;
    for(int i=0; i<n; i++){
        int h=0;
        for(int a=0; a<l; ++a) 
        for(int b=0; b<l; ++b)
        for(int c=0; c<l; ++c)
        for(int d=0; d<l; ++d, ++h){
          if(a+b+c+d != psum[i]) continue;
          // cout << a << b << c << d << " ? " << psum[i] << endl;
          aux[h] = 0;
          
          vector<int> ev = {d, c, b, a};
          // db(cod(ev, l));
          // db(h);
          for(int p=0; p<4; ++p) {
              if(q[i]+1 <= ev[p]) {
                  int sub = q[i] + 1;
                  ev[p] -= sub;
                  aux[h] |= dp[cod(ev, l)];
                  ev[p] += sub;
              }
          }
          if(aux[h]){
            // cout << a << b << c << d << endl;
            ans = i+1;
          }
          // h++;
        } 
        dp = aux ;
    }

    cout << ans << endl;
}