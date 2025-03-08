#include <stdio.h>

#define MAXN 5000

int A[MAXN], LDS[MAXN], LIS[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Tìm dãy giảm dài nhất (LDS) từ trái sang phải
    for (int i = 0; i < N; i++) {
        LDS[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i] && LDS[i] < LDS[j] + 1) {
                LDS[i] = LDS[j] + 1;
            }
        }
    }

    // Tìm dãy tăng dài nhất (LIS) từ phải sang trái
    for (int i = N - 1; i >= 0; i--) {
        LIS[i] = 1;
        for (int j = N - 1; j > i; j--) {
            if (A[j] > A[i] && LIS[i] < LIS[j] + 1) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }

    // Tìm dãy lõm dài nhất
    int maxLomLength = 0;
    for (int i = 0; i < N; i++) {
        if (LDS[i] > 1 && LIS[i] > 1) { // Điểm giữa phải hợp lệ
            int lomLength = LDS[i] + LIS[i] - 1;
            if (lomLength > maxLomLength) {
                maxLomLength = lomLength;
            }
        }
    }

    // Nếu không tìm được dãy lõm hợp lệ
    if (maxLomLength < 3) {
        printf("0\n");
    } else {
        printf("%d\n", maxLomLength);
    }

    return 0;
}
