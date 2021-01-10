#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::pair;

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
  int x = a[k];
  int m1 = k;
  int m2 = m1+1;
  for (int i = l; i < r; ) {

      if (a[i]==x){
          int ic = m2;
          if (ic == r){
              m1--;
              ic = m1;
          }
          else
              m2++;
          swap(a[i],a[ic]);
          m2++;
      }
      else if (a[i] > x) {
          swap(a[i],a[m2]);
      }
      else
          i++;
  }
 #if defined TEST1
  for (int i=0;i<r;i++){
      std::cout << i << " " << a[i] <<std::endl;
  std::cout << "partitioned" << std::endl;
 #endif
  return pair<int,int>(m1,m2);
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int,int> m = partition3(a, k, l, r);

  randomized_quick_sort(a, l, m.first);
  randomized_quick_sort(a, m.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
