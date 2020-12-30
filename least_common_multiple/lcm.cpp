#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int current_gcd = 1;
    int na = a;
    int nb = b;
    for (;;){
        if (na < nb){
            int rem = nb % na;
            if (rem == 0){
                current_gcd = na;
                break;
            }
            nb = rem;
        }
        else {
            int rem = na % nb;
            if (rem == 0){
                current_gcd = nb;
                break;
            }
            na = rem;
        }
    }
    return current_gcd;
}

long long lcm_naive(int a, int b) {
// See https://en.wikipedia.org/wiki/Least_common_multiple
#if defined BRUTE
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
#else
    long long abgcd = (long long) gcd(a,b);
     return (a/abgcd)*b;
#endif
}

int main() {
  int a, b;
//  a = 714552;
//  b = 374513;
  cin >> a >> b;
  cout << lcm_naive(a, b) << std::endl;
  return 0;
}
