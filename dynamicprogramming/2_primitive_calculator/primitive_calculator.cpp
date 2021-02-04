#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::vector;

//#define TEST 1

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> operMin(int n) {
    vector<int> oper;
    oper.push_back(0);
    for (size_t i = 1; i <= n; i++) {
// oper(i) = min(oper(n/3)+1, oper(n/2)+1, oper(n-1)+1)
        int current = oper[i-1l];
        if (i % 3 == 0) {
            int minc1 = oper[i/3];
            if (minc1 < current)
                current = minc1;
        }
        if (i % 2 == 0) {
            int minc2 = oper[i/2];
            if (minc2 < current)
                current = minc2;
        }
//        std::cout << "current " << i << " " << current << std::endl;
        oper.push_back(current+1);
     }
    return oper;
}

vector<int> optimal_sequence_dp(int n) {
    vector<int> oper = operMin(n);
    vector<int> sequence;
    if (n == 0) {
        sequence.push_back(1);
        sequence.push_back(0);
        return sequence;
    }
    if (n == 1) {
        sequence.push_back(1);
        return sequence;
    }
    while (n >= 1) {
        sequence.push_back(n);
        bool isDiv3 = n % 3 == 0;
        bool isDiv2 = n % 2 == 0;
        int nm1 = n - 1;
        if (!isDiv3 && !isDiv2) {
            n = nm1;
        }
        else if (isDiv3 && !isDiv2) {
            if (oper[nm1] <= oper[n/3])
                n = nm1;
            else
                n = n / 3;
        }
        else if (isDiv2) {
            if (oper[nm1] <= oper[n/2])
                n = nm1;
            else
                n = n / 2;
        }
        else if (isDiv3) {
            if (oper[nm1] <= oper[n/3])
                n = nm1;
            else
                n = n / 3;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
#if defined TEST
    std::srand(134);
    int nsamples = 10;
    for (int i = 0; i < nsamples; i++) {
        int n = std::rand();
        vector<int> sequence = optimal_sequence_dp(n);
        std::cout <<"\nFor random sample " << n << " " << sequence.size() - 1 << std::endl;
        for (size_t i = 0; i < sequence.size(); ++i) {
            std::cout << sequence[i] << " ";
    }
#else
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence_dp(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
#endif
  }
}
