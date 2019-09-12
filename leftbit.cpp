//Finding the most significant bit of a (int-32bit) number

//The goal is to fill n with a bunch of ones behind (at right)
//the most left 1 already existent bit
//The hint is: think in the worst case,
//that is, a power of two, because it has just one true bits
//and the biggest one: 2 to the power of 31;

int leftbit(int n){
  n|=n>>1, n|=n>>2, n|=n>>4, n|=n>>8, n|=n>>16;
  n++;
  return (n<<1);
}
