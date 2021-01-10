#include <algorithm>
#include <iostream>
#include <vector>

//#define TEST1

using std::vector;

class Node {
  public:
    Node(const int &a) {
       value = a;
       count = 1;
       left = NULL;
       right = NULL;
    }
    int value;
    int count;
    Node *left;
    Node *right;
};


Node *addNode(int a, Node *tree)
{
   Node *current = tree;
   for (;;){
       if (current == NULL)
           break;
       if (a == current->value){
           current->count++;
           return current;
       }
       if (a < current->value)
           current = current->left;
       else
           current = current->right;
   }
   current = new Node(a);
   return current;
}

//Get count of element iel in subarray a[left:right]
int getCount(vector<int>a, int left, int right, int iel)
{
   int count = 0;
   for (int i=left;i<right;i++)
       if (a[i]==iel)
           count++;
   return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
// If an element is a majority it will be a majority in at least one half
#if defined TEST1
    std::cout << "Function called with range " << left << " " << right << std::endl;
    if (left+1 == right)
        std::cout << "Returns " << a[left] << std::endl;
#endif
    if (left+1 == right)
          return a[left];
    if (left+2 == right) {
          if (a[left]==a[left+1])
              return a[left];
          else
              return -1;
    }

    int imid = (right - left)/2;

    int i1 = get_majority_element(a, left, left + imid);
    int i2 = get_majority_element(a, left + imid, right);
#if defined TEST1
    std::cout << "First half " << i1 << " subrange " << left << " " << imid << std::endl;
    std::cout << "Second half " << i2 << " subrange " << imid << " " << right << std::endl;
#endif

    if (i1==i2)
        return i1;

    if (i1 != -1) {
        int i1count = getCount(a,left,right,i1);
#if defined TEST1
        std::cout << "Count for i1 " << i1 << " is = " << i1count << std::endl;
        if (i1count > imid)
            std::cout << "Contender" << std::endl;;
#endif
        if (i1count > imid)
            return i1;
    }
    if (i2 != -1) {
        int i2count = getCount(a,left,right,i2);
#if defined TEST1
    std::cout << "Count for  i2 " << i2 << " is = " << i2count << std::endl;
    if (i2count > imid)
        std::cout << "Contender" << std::endl;
#endif
        if (i2count > imid)
            return i2;
    }

    return -1;
}

int get_majority_element_tree(vector<int> &a, int left, int right) {
// Sort counting #of elements
    if (left == right)
        return 0;
    int maxval = (left + right)/2;
    Node *tree = new Node(a[0]);
    for (int i=left+1; i<right; i++){
        Node *current = addNode(a[i], tree);
#if defined TEST1
        std::cout << "Node " << current->value << " count " << current->count << std::endl;
        std::cout << "maxval " << maxval << std::endl;
#endif
        if (current->count > maxval)
            return i;
    }
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
