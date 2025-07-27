#include <stdio.h>

/*
    Kiến thức quan trọng:
    - Số bội của 1 số từ 1 -> N: là kết quả của phép chia N cho số đó
*/

// Hàm đếm số lượng số là bội của 3 hoặc 5 từ 1 đến N
unsigned long long countMultiples(long long N) {
    long long count3 = N / 3;
    long long count5 = N / 5;
    long long count15 = N / 15; 
    // Vì 15 cũng là bội của và cả 5 => sẽ bị đếm 2 lần => trừ bớt đi 1 lần

    return count3 + count5 - count15;
}

int main() {
    int T;
    scanf("%d", &T);

    unsigned long n[T];

    for (int i = 0; i < T; i++)
    {
        scanf("%lu", &n[i]);
    }

    for (int i = 0; i < T; i++)
    {
        printf("%llu\n",countMultiples(n[i]));
    }

    return 0;
}
