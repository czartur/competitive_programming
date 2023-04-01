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
const int N =1e5+5;

struct tripla{
  int q, a, i;

  bool operator<(const tripla &t) const{
    if(q != t.q) return q < t.q;
    if(a != t.a) return a < t.a;
    return i < t.i;
  }
};
void solve(int n, int b){
  priority_queue<tripla> pq;
  while(n--) {
    int a; cin >> a;
    pq.push({inf, a, 0});
  }

  while(b--){
    tripla cur = pq.top();
    pq.pop();
    ++cur.i;
    cur.q = (cur.a+cur.i-1)/cur.i;
    pq.push(cur);
  }
  int ans = 0;
  while(!pq.empty()){
    tripla cur = pq.top();
    ans = max(ans, cur.q);
    pq.pop();
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(true){
    int n, b;
    cin >> n >> b;
    if(n == -1 && b == -1) return 0;
    solve(n, b); 
  }
}
