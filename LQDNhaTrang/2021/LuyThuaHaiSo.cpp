#include <stdio.h>
#include <math.h>

// Hàm kiểm tra xem a^b có đúng bằng n hay không, tránh tràn số
long long power(long long a, long long b, long long n) {
    long long result = 1;
    for (long long i = 0; i < b; i++)  //lặp lại b lần
    {
        if (result > n / a) return -1; // Tránh tràn số
        result *= a;
    }
    return result; 
}

void solve(long long n, long long k) {
    long long min_a = -1, min_b = -1;

    for (long long a = 1; a * a <= n; a++) {  // Chỉ cần xét đến sqrt(n)
        long long b = log(n) / log(a);  // Tính b gần đúng bằng log a ^ b = n => b*loga (bay mũ) = log n => b = logn / loga
        for (long long i = b - 1; i <= b + 1; i++) { // Kiểm tra xung quanh b
            if (i < 1) continue;
            if (power(a, i, n) == n && a + i == k) {
                if (min_a == -1 || a < min_a) //nếu chưa gán minA hoặc số a mới bé hơn min
                {
                    min_a = a;
                    min_b = i;
                }
            }
        }
    }

    if (min_a == -1)
        printf("-1\n");
    else
        printf("%lld %lld\n", min_a, min_b);
}

int main() {

    long long n, k;
    scanf("%lld%lld",&n,&k);

    solve(n, k);
    return 0;
}
