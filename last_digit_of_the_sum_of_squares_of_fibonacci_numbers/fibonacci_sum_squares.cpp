#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

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


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;
    long long mm = 3;
    if (m > 2) mm = pisano_period(m);
    long long nn = n % mm;
//    cout << "reduced number " << nn << " mm " << mm << " m " << m << endl;
    long long current = last_digit(nn,m);
    return current;
}

int fibonacci_sum_squares(long long n) {
    long long mm = pisano_period(10);
    long long nn = n % mm;
    long long nnp1 = (n+1)%mm;
    int nn1 = (int)last_digit(nn,10);
    int nnp11 = (int)last_digit(nnp1,10);
//    std::cout << "for n " << nn1 << std::endl;
//    std::cout << "for n+1 " << nnp11 << std::endl;
    return (nn1*nnp11) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}
