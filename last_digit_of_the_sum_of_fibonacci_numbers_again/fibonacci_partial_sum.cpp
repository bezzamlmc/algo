#include <iostream>
#include <vector>
using std::vector;

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


long long get_fibonacci_partial_sum(long long from, long long to){
    if (from == 0 && to <= 1)
        return to;
    if (from == 1 && to ==1)
        return to;
//https://www.geeksforgeeks.org/sum-fibonacci-numbers/
    long long minus = 0;
    if (from > 0)
        minus = fibonacci_faster_last_digit(from+1) - 1;
    long long all = fibonacci_faster_last_digit(to+2) - 1;
//    std::cout << "nn " << nn << std::endl;
    int ll = all - minus;
    if (ll < 0) ll = ll + 10;
    return ll;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
