#include <bits/stdc++.h>
using namespace std;
//www.spoj.com/problems/EDIST/en/
string a, b;
int dp[2005][2005];

int func(int m, int n){
    if(dp[m][n]!=-1) return dp[m][n];
    if(!m||!n) return dp[m][n]=max(m, n);
    if(a[m-1]==b[n-1]) return dp[m][n]=func(m-1, n-1);
    //delete from m, delete from n, replace a letter
    return dp[m][n]=min(func(m-1,n)+1, min(func(m,n-1)+1, func(m-1,n-1)+1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        memset(dp, -1, sizeof(dp));
        cin >> a >> b;
        cout << func(a.size(), b.size()) << endl;
    }
}
