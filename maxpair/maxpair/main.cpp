#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int> &myVector)
{
    long long result = 0L;
    size_t vSize = myVector.size();
    if (vSize == 0)
        return result;
    if (vSize == 1)
        return result;
    std::vector<int> copyVector = myVector;
    std::sort(copyVector.begin(), copyVector.end());
    if (copyVector[0] < 0 && copyVector[1] < 0)
        result = (long long)copyVector[0]*(long long)copyVector[1];
    long long val = (long long)copyVector[vSize-1]*(long long)copyVector[vSize-2];
    if (val > result)
        return val;
    else
        return result;
}

int main()
{
#if defined TEST
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
#else
    int n;
    std::cin >> n;
    std::vector<int> test(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> test[i];
    }
#endif
    long long result = MaxPairwiseProduct(test);
    cout << result << endl;
    return 0;
}
