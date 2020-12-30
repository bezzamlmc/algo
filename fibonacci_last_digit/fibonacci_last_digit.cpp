#include <iostream>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int  previous = 0;
    int current  = 1;

//    cout << "Will loop for n " << n << endl;
    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current % 10;
// Throw away multiple of 10's
//        cout << i <<" " <<  current << endl;
    }

    return current;
}

int main() {
    int n;
    cin >> n;
//    cout << "User input: " << n << endl;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    }
