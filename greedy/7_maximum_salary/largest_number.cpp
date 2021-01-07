#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::min;

// Returns true if a is greater or equal to b with the criteria of concatenating
bool isGreaterOrEqual(const string &a, const string &b)
{
 string ab = a+b;
 string ba = b+a;
 return (ab.compare(ba) > 0);
}

string largest_number(vector<string> a) {
// Safe move - pick the instance that is greater or equal in terms of digits
  sort(a.begin(), a.end(), isGreaterOrEqual);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
