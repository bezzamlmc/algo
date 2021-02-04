#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get_change(int m) {
//Returns the minimum number of coins that add up to m with combinations of 1, 3, 4
	if (m == 0)
		return 0;
	int count = INT_MAX;
	vector<int> coins{ 1,3,4 };
	vector<int> mincoin(m);
	int nCoins = coins.size();
	for (unsigned int i = 1; i <= m; i++) {
		count = INT_MAX;
		for (unsigned int j = 0; j < nCoins; j++) {
			int current = i - coins[j];
			unsigned int im1 = i - 1;
			if (current == 0) {
				mincoin.at(im1) = 1;
				count = 1;
			}
			else if (current > 0) {
				int currentCount = mincoin[current-1] + 1;
				if (currentCount < count) {
					mincoin.at(im1) = currentCount;
					count = currentCount;
				}
			}
		}
	}
	return mincoin[m-1];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
