
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cod(vector<int> coef, int l){
    int f=1, ans = 0;
    sort(coef.begin(), coef.end());
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
    vector <int> q(n);
    for(auto& val : q) cin >> val;
    
    ++l;
    int L = l*l*l*l;
    vector <int> dp(L), aux(L);
    for(int i=n-1; i>=0; i--) {
        int h=0;
        for(int a=0; a<l; ++a) 
        for(int b=a; b<l; ++b)
        for(int c=b; c<l; ++c)
        for(int d=c; d<l; ++d){
            vector<int> ev{d,c,b,a};
            h = cod(ev, l);
            aux[h] = 0;
            for(int p=0; p<4; ++p) {
                if(q[i] <= ev[p]) {
                    int sub = q[i] + (q[i] < ev[p]);
                    ev[p] -= sub;
                    aux[h] = max(aux[h], 1 + dp[cod(ev, l)]);
                    ev[p] += sub;
                }
            }
        }
        dp = aux ;
    }

    cout << dp.back() << endl;
}