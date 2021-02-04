#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::pair;

#define TEST1 1

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

//Will partition array in [elements < x, elements=x, elements>x]
pair<int,int> partition3(vector<int> &a, int k, int l, int r) {
    if (l+1 == r)
        if (a[l]>a[r])
            swap(a[l],a[r]);
  int x = a[k];
  int m1 = l;
  int j = l;
  int m2 = r - 1;
  while (j <= m2) {
      if (a[j] < x){
          swap(a[j],a[m1]);
          m1++;
          j++;
      }
      else if (a[j] > x){
          swap(a[j],a[m2]);
          m2--;
          continue;
      }
      else
          j++;
  }
  return pair<int,int>(m1,m2);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  pair<int,int> m = partition3(a, k, l, r);

  randomized_quick_sort3(a, l, m.first);
  randomized_quick_sort3(a, m.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
