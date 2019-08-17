
// b tends to zero with a bunch of returns;
int gcd(int a, int b){
 return b ? gcd(b, a%b) : a;
}
