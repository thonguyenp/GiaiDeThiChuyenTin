#include <stdio.h>
#include <math.h>

// Hàm tính tổng 1^2 + 2^2 + ... + m^2
unsigned long long sum_of_squares(unsigned long long m) {
    return (m * (m + 1) * (2 * m + 1)) / 6;
}

// Tìm m lớn nhất sao cho sum_of_squares(m) <= x
unsigned long long find_max_m(unsigned long long x) {
    unsigned long long left = 0, right = 1000000; // sqrt(10^18) ~ 10^9
    unsigned long long result = 0;
    while (left <= right) {
        unsigned long long mid = left + (right - left) / 2;
        if (sum_of_squares(mid) <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    unsigned long n;

    // Đọc n
    scanf("%lu", &n);
    unsigned long long x[n];

    // Đọc mảng x
    for (unsigned long i = 0; i < n; i++) {
        scanf("%llu", &x[i]);
    }

    // Xử lý từng x[i]
    for (unsigned long i = 0; i < n; i++) {
        unsigned long long count = find_max_m(x[i]);
        printf("%llu ", count);
    }

    return 0;
}