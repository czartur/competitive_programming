// pre-calculate LPS (longest proper prefix which is also a suffix)
// for every substring [0 ... i] of pat
vector<int> lps_build(string& pat){
  int m = pat.size();
  vector<int>lps(m);
  
  for(int i=1, len=0; i<m; i++){ // len keeps track of last lps found for each iter. 
    while(len>0 && pat[i]!=pat[len]) len=lps[len-1]; 
    if(pat[i] == pat[len]) lps[i] = ++len;
  }
  
  return lps;
}

// kmp itself 
int kmp(string& pat, string &s, vector<int> &lps){ 
  int n = s.size();
  
  for(int i=0, j=0; i<n; i++){
    while(j>0 && s[i] != pat[j]) j=lps[j-1];
    if(s[i] == pat[j]) j++;
    
    if(j == pat.size()) return i+1-j; //return index of matching position
  }
  
  return -1;
}

// GOAL : find pattern in string
// Complexity : O(n+m) 
