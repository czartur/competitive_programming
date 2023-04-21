#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl

int cod(vector<int> coef, int l){
  sort(coef.begin(), coef.end());
  int ans = 0;
  for(int i=0, f=1; i<4; ++i, f*=l){
    ans += coef[i]*f;
  }
  return ans;
}

void build(int l, unordered_map<int, int> &umapa){
  int h = 0;
  for(int a=0; a<l; ++a) 
  for(int b=a; b<l; ++b)
  for(int c=b; c<l; ++c)
  for(int d=c; d<l; ++d){
    vector<int> ev{a,b,c,d};
    umapa[cod(ev, l)] = h++;
  }
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
    int L = ((l+3)*(l+2)*(l+1)*l)/24;
    unordered_map<int, int> umapa;
    build(l, umapa);
    vector <int> dp(L), aux(L);
    dp[0] = 1;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        int h = 0;
        for(int a=0; a<l; ++a) 
        for(int b=a; b<l; ++b)
        for(int c=b; c<l; ++c)
        for(int d=c; d<l; ++d, ++h){
          if(a+b+c+d != psum[i]) continue;
            vector<int> ev{a,b,c,d};
            aux[h] = 0;
            for(int p=3; p>=0; --p) {
              if(q[i] + 1 > ev[p]) break;
              int sub = q[i] + 1;
              ev[p] -= sub;
              aux[h] |= dp[umapa[cod(ev, l)]];
              ev[p] += sub;
            }
            if(aux[h]) ans = i+1;
        }
        dp = aux;
    }
    cout << ans << endl;
}