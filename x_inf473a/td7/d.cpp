#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1001113;
const int N =1e5+5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int start; cin >> start;
  cin.ignore();
  vector<int> par(100);

  string line;
  while(getline(cin, line)){
    stringstream ss(line); 
    if(line == "-1") break;
    int pai; ss >> pai;
    int filho;
    while(ss >> filho) par[filho] = pai;
  }

  int cur = start;
  while(cur){
    cout << cur << " ";
    cur = par[cur]; 
  }
  cout << endl;
}
