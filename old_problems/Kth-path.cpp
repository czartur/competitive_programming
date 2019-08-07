#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

int main(){
  int n, m, k;
  ll dist[405][405];
  ll ans[16025];
  map <int, int> pam;
  vector <piii> v;
  scanf("%d%d%d", &n, &m, &k);
  for(int i=1; i<=m; i++){
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    v.pb({w, {x,y}});
  }
  sort(v.begin(), v.end());

  //enumeração
  int key=1;
  for(int i=0; i<v.size(); i++){
    if(!pam.count(v[i].nd.st)) pam[v[i].nd.st]=key++;
    if(!pam.count(v[i].nd.nd)) pam[v[i].nd.nd]=key++;
  }
  for(int i=1; i<key; i++){
    for(int j=1; j<key; j++){
      dist[i][j]=LINF;
    }
  }
  for(int i=0; i<k; i++){
    dist[pam[v[i].nd.st]][pam[v[i].nd.nd]]=dist[pam[v[i].nd.nd]][pam[v[i].nd.st]]=v[i].st;
  }

  for(int a=1; a<key; a++){
    for(int b=1; b<key; b++){
      for(int c=1; c<key; c++){
        dist[b][c]=dist[c][b]=min(dist[c][b], dist[c][a]+dist[a][b]);
        if(b==c) dist[b][c]=dist[c][b]=0;
      }
    }
  }

  int g=1;
  for(int j=1; j<key; j++){
    for(int i=j+1; i<key; i++){
      ans[g++]=dist[j][i];
    }
  }
  sort(ans+1, ans+g);
  //printf("%d\n", key);
  printf("%lld\n", ans[k]);
}
