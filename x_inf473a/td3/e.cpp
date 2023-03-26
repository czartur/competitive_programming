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

bool can(int pos, int &carry, vector<string> &words, vector<int> &mp){
  // cout << "OI " << pos << endl;
  int sum = carry;

  // for(auto &word : words){
  //   for(auto l : word) cout << mp[l-'A'] << " ";
  //   cout << endl;
  // }
  for(int i=0; i<words.size()-1; i++){
    sum+=mp[words[i][pos]-'A'];
  }
  carry = sum/10;
  // db(sum);
  // if(sum%10 == mp[words.back()[pos]-'A']) cout << "TRUE" << endl;
  // else cout << "FALSE" << endl;
  return (sum%10 == mp[words.back()[pos]-'A']);
}

void bt(int s, int pos, int &carry, int &ans, vector<string> &words, vector<int> &mp, vector<int> &pm){
  int m = words[0].size();
  if(pos == m) {
    // ans += !carry;

    if(true){
      // cout << "DONE!" << endl;
      int sum = 0;
      for(int i=0; i<words.size(); i++){ 
        int pot = (i==words.size()-1) ? 1 : -1;
        for(auto l : words[i]) sum += pot*mp[l-'A'], pot*=10;
      }
      ans += (sum==0);
    }
    return;  
  }

  // db(words.size());
  if(s == words.size()) {
    int aux = carry;
    if(can(pos, carry, words, mp)) bt(0, pos+1, carry, ans, words, mp, pm);
    carry = aux;
    return;
  }

  // db(s); db(pos);
  int l = words[s][pos]-'A';
  if(pos == words[0].size()-1 && words[s][pos] != 'Z' + 1 && mp[l] == 0) return;

  if(~mp[l]) bt(s+1, pos, carry, ans, words, mp, pm);
  else {
    for(int dig = (pos==m-1 || (pos+1<m && words[s][pos+1] == 'Z'+1)); dig<=9; ++dig){
      if(~pm[dig]) continue;

      // db(s); db(pos); db(dig);
      mp[l] = dig;
      pm[dig] = l;
      bt(s+1, pos, carry, ans, words, mp, pm);
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

  for(int i=0; i<words.size(); ++i) {
    reverse(words[i].begin(), words[i].end());
    if(i<words.size()-1) while(words[i].size() < words.back().size()) words[i].push_back('Z'+1);
  }
  mp['Z'+1-'A']=0;
  int ans = 0, carry = 0;
  bt(0,0,carry,ans,words,mp, pm);
  cout << ans << endl;
}
