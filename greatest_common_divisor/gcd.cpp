#include <iostream>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
 #if defined BRUTE_FORCE
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
 #else
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
//            cout << "new case a " << na << " " << nb <<endl;
        }
        else {
            int rem = na % nb;
            if (rem == 0){
                current_gcd = nb;
                break;
            }
            na = rem;
//           cout << "new case b " << na << " " << nb <<endl;
        }
    }
 #endif
  return current_gcd;
}

int main() {
  int a, b;
  cin >> a >> b;
//  a = 14159572;
//  b = 63967072;
  cout << gcd_naive(a, b) << std::endl;
  return 0;
}
