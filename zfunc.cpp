//clean code, working

int z[N];

void z(int n){
  int l=0, r=0;
  if(i<=r) z[i]=min(z[i-l], r-l+1);
  while(i+z[i]<n && s[i+z[i]]==s[z[i]]);
  if(i+z[i]-1>r) l=i, r=i+z[i]-1;
}
