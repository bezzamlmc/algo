#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int current = 1;
  int rest = n;
  for(;;){
      if ((rest-current) > current){
          summands.push_back(current);
          rest -= current;
          current++;
      }
      else {
          summands.push_back(rest);
          break;
      }
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
