// tested & working
// constructor --> singletons / each element is its own parent (0-indexed)

class DSU{
  vector<int> par;
  vector<int> weight;

  public:
  int size;
  
  DSU(int n) : size{n}{
    par.resize(n);
    weight.resize(n);
    iota(par.begin(), par.end(), 0); // singletons
  }

  int find(int a){
    if(par[a]==a) return a;
    return par[a]=find(par[a]);
  }

  void join(int a, int b){
    a=find(a), b=find(b);
    if(a != b) size--;
    if(weight[a]<weight[b]) swap(a,b);
    par[a]=b;
    weight[b]+=weight[a];
  }
}; 
