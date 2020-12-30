#include <iostream>

long long pisano_period(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return m;
}

long long last_digit(long long n,long long m)
{
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current  = 1;
    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current % m;
    }
    return current;
}


long long fibonacci_faster_last_digit(long long n) {
    if (n <= 1)
        return n;
    int  mm = pisano_period(10);
    long long nn = n % mm;
    long long current = last_digit(nn,10);
    return current;
}

long long fibonacci_fast_last_digit(long long n) {
    // write your code here
//    std::cout << "Compute for " << n << std::endl;
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current = 1;
    for (int i=2;i<=n;i++) {
        long long tmp = previous;
        previous = current;
        current = tmp + previous;
        current = current % 10;
//        std::cout << tmp << " " << previous << " " << current << std::endl;
    }
    return current;
}

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }
    return sum % 10;
}

int fibonacci_sum(long long n){
//https://www.geeksforgeeks.org/sum-fibonacci-numbers/
    long long nn = fibonacci_faster_last_digit(n+2);
//    std::cout << "nn " << nn << std::endl;
    int ll = nn - 1;
    if (ll < 0) ll = 9;
    return ll;
}

int main() {
    long long n = 0;
    std::cin >> n;
//    std::cout << fibonacci_sum_naive(n);
    std::cout << fibonacci_sum(n);
}
