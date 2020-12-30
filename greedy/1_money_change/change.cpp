#include <iostream>

int get_change(int m) {
    int coins[3] = {10, 5, 1};
    int mtot = m;
    int n = 0;
    for (int i=0;i<3;i++){
        int mm = mtot / coins[i];
        if (mm > 0) {
            n += mm;
            mtot = mtot - mm*coins[i];
            if (mtot == 0)
                break;
        }
    }
    return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
