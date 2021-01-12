#include <iostream>
#include <vector>

//#define TEST1 1

using std::vector;

long long get_number_of_inversions_old(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) 
      return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions_old(a, b, left, ave);
  number_of_inversions += get_number_of_inversions_old(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

//Merge two sorted arrays into d and resturn number of inversions where (a>b)
long long mergeAndCountInversions(vector<int>&a, vector<int>&b, vector<int> &d)
{
    long long count = 0;
    size_t ia = 0;
    size_t ib = 0;
    size_t id = 0;
    size_t la = a.size();
    size_t lb = b.size();
#if defined TEST1
    std::cout << " a: " ;
    for (size_t i=0; i<a.size();i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << " b: " ;
    for (size_t i=0; i<b.size();i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;
#endif
    int isweepb = 0;
    for(;;){
        if (ia >= la){
// Copy remaining b - no a's left
            while (ib < lb)
                d[id++] = b[ib++];
            break;
        }
        if (ib >= lb){
//Copy remaining a - no b's left - all of these a's are greater than last sweep of b's so they need to be counted
            while (ia < la) {
#if defined TEST1
                std::cout << "tail count (" << a[ia] << ", " << b[lb - 1] << ")" << std::endl;
#endif
                count += isweepb;
                d[id++] = a[ia++];
            }
            break;
        }
        if (a[ia] <= b[ib]) {
            d[id++] = a[ia++];
                count += isweepb;
        }
        else {
#if defined TEST1
            std::cout << "regular count (" << a[ia] << ", " << b[ib] << ")" << std::endl;
#endif
            d[id++] = b[ib++];
            isweepb++;
        }
    }
#if defined TEST1
    std::cout << " d: " ;
    for (size_t i=0; i<d.size();i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
    std::cout << "count: " << count << std::endl;
#endif
    return count;
}

//Grab a, returned ordered b and #of counts
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) {
      b[0] = a[left];
      return number_of_inversions;
  }
  size_t ave = left + (right - left) / 2;
  vector<int> c(ave-left), d(right-ave);
  number_of_inversions += get_number_of_inversions(a, c, left, ave);
  number_of_inversions += get_number_of_inversions(a, d, ave, right);
  number_of_inversions += mergeAndCountInversions(c,d,b);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
