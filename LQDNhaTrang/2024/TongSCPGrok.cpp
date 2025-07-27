#include <stdio.h>
#include <math.h>

/*
    Kiến thức cần nhớ:
    - Công thức tính bình phương từ 1 -> m
    - TÌm kiếm nhị phân:
        + Cách đặt left + (right - left) / 2 để tránh tràn số
        + Phương pháp tìm kiếm nhị phân
*/

// Hàm tính tổng 1^2 + 2^2 + ... + m^2
unsigned long long sum_of_squares(unsigned long long m) {
    return (m * (m + 1) * (2 * m + 1)) / 6;
}

// Tìm m lớn nhất sao cho sum_of_squares(m) <= x (dùng binary search)
unsigned long long find_max_m(unsigned long long x) {
    unsigned long long left = 0, right = x;
    unsigned long long result = 0;
    while (left <= right) {
        //left + (right - left) / 2 tốt hơn (left + right)/2 vì (left + right) có thể bị tràn số
        unsigned long long mid = left + (right - left) / 2; 
        /*
        Nguyên tắc tìm kiếm nhị phân:
        - Nếu tổng bình phương từ 1 đến mid <= x => số hơi nhỏ => tăng biên trái lên mid+1
        - Nếu tổng bình phương từ 1 đến mid > x => số hơi lớn => tăng biên phải về mid-1
        */
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