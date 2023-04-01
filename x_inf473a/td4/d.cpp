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

struct activity{
  int s, e;
  bool operator<(const activity& act) const{
    return e == act.e ? s < act.s : e < act.e;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k; cin >> n >> k;
  vector<activity> events(n);
  for(auto& val : events) cin >> val.s >> val.e;
  
  sort(events.begin(), events.end());

  multiset<int, greater<int>> dispo;

  // put first k values
  for(int i=0; i<k; ++i) dispo.insert(0);
  
  int ans = 0;
  for(int i=0; i<n; ++i){
    activity event = events[i];
    // search biggest end time smaller than event's start timea
    auto it = dispo.upper_bound(event.s);
    if(it == dispo.end()) continue;
    dispo.erase(it);
    dispo.insert(event.e);
    ++ans;
  }
  cout << ans << endl;
}


/*
sort by end times

4 3
1 3
1 3
3 4

3 5
2 7

*/