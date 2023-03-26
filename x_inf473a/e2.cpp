#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
// #define mp make_pair
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

// check sum
bool can(vector<string> &words, vector<int> &mp){
    int n = words.size();
    int sum = 0, pot;
    for(int i=0; i<n; i++){ 
        pot = (i==n-1) ? 1 : -1; // we subtract in the last
        for(auto l : words[i]) sum += pot*mp[l-'A'], pot*=10;
    }
    return (sum == 0);
}

// backing track
void bt(int s, int pos, int &ans, vector<string> &words, vector<int> &mp, vector<int> &pm){
  int m = words[0].size(), n = words.size(); 
  
  if(pos == m) { bt(s+1, 0, ans, words, mp, pm); return; }
  
  if(s == n) {ans += can(words, mp); return; }

  int l = words[s][pos]-'A';

  if(~mp[l]) bt(s, pos+1, ans, words, mp, pm);
  else {
    for(int dig = (pos==m-1 || (pos+1<m && words[s][pos+1] == 'Z'+1)); dig<=9; ++dig){
      if(~pm[dig]) continue;

      mp[l] = dig;
      pm[dig] = 1;
      bt(s, pos+1, ans, words, mp, pm);
      mp[l] = -1;
      pm[dig] = -1;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<string> words(n);
  vector<int> mp(27, -1), pm(10, -1);
  for(auto &word : words) cin >> word;

  // equalize string sizes
  for(int i=0; i<words.size(); ++i) {
    reverse(words[i].begin(), words[i].end());
    // put dumb character
    if(i<words.size()-1) while(words[i].size() < words.back().size()) words[i].push_back('Z'+1);
  }
  
  // 0 for the dumb character
  mp['Z'+1-'A']=0;
  int ans = 0;
  bt(0,0,ans,words,mp, pm);
  cout << ans << endl;
}
