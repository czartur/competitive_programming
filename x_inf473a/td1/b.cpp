#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x,y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;


const int N = 1234;
const int M = 5678;

void print(vi &r, vi &c){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cout << r[i]*M + c[j] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> mat(N, vector<int>(M));

  int cur = 1;

  vi row(N+1), col(M+1), irow(N+1), icol(M+1);
  iota(irow.begin(), irow.end(), 0);
  iota(row.begin(), row.end(), 0);
  iota(col.begin(), col.end(), 0);
  iota(icol.begin(), icol.end(), 0);

  char c;
  while(cin >> c){ 
    if(c == 'R'){
      int x, y; cin >> x >> y;
      swap(row[x], row[y]);
      irow[row[x]] = x;
      irow[row[y]] = y;
    }
    if(c == 'C'){
      int x, y; cin >> x >> y;
      swap(col[x], col[y]);
      icol[col[x]] = x;
      icol[col[y]] = y;
    }
    if(c == 'Q'){
      int x, y; cin >> x >> y;

      x = row[x], y = col[y];
      //db(x), db(y);
      cout << (x-1)*M + y << endl;
    }
    if(c == 'W'){
      int z;
      cin >> z;
      z--;
      int x = irow[z/M +1], y=icol[z%M + 1];
      cout << x << " " << y << endl;
    }
    if(c == 'X') break;
  }
}
