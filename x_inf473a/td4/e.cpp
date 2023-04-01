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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, row, c; cin >> n >> row >> c;
  vector<pair<int,int>> intervals(n);

  for(auto& [l,r] : intervals){
    int a, b, s; cin >> a >> b >> s;
    l = max(1, a-s), r = min(row, a+s);
  }

  // sort by start time
  sort(intervals.begin(), intervals.end());

  // why not a min_queue ? its just harder to implement 
  priority_queue<int, vector<int>, greater<int>> pq;
  auto cur = intervals.begin();
  int ans = 0;
  for(int i=1; i<=row; ++i){
    // insert every start time before i
    while(cur != intervals.end() && cur->first <= i) 
      pq.push(cur->second), ++cur;

    int count = 0;
    while(!pq.empty() && count < c){
      // assign first end time after i (or discard if before i)
      int end = pq.top(); pq.pop();
      if(end < i) continue;
      ++ans; ++count;
    }
  }
  cout << ans << endl;
}
