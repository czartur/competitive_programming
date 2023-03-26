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

  unordered_map<string, string> dialog;
  
  int n; cin >> n;
  for(int i=0; i<n; i++){ 
    string name, text;
    cin >> name;
    getline(cin, text);
    dialog[name] += " " + text;
  }

  // add all words
  unordered_map<string, int> outter;
  unordered_map<string, int> freq;
  for(auto& [name, text] : dialog){
    stringstream ss(text);
    string word;
    unordered_set<string> inner;
    while(ss >> word) ++freq[word], inner.insert(word);
    for(auto& s : inner) ++outter[s];
  }

  vector<pair<int, string>> lista;
  for(auto& [word, f]: freq){
    if(outter[word] < dialog.size()) continue;
    lista.push_back({-f, word});
  }

  if(lista.empty()) cout << "ALL CLEAR" << endl;
  else {
    sort(lista.begin(), lista.end());
    for(auto& p: lista) cout << p.second << endl;
  }
}
