#include <stdio.h>

#define MAXN 5000

int A[MAXN], LDS[MAXN], LIS[MAXN];

int max (int a, int b)
{
    return (a > b) ? a : b;
}
/*
Để tìm dãy lõm dài nhất mà cần xóa ít phần tử nhất:
B1. Tìm dãy giảm (giảm theo chiều từ trái sang phải) không liên tục từ trái sang phải (LDS)
B2. Tìm dãy giảm (giảm theo chiều từ phải sang trái) không liên tục từ phải sang trái (LIS) 
B3. Tại vị trí mà tổng 2 phần tử của LDS và LIS lớn nhất thì đó là vị trí lõm vì trước vị trí đó
có dãy giảm dài nhất không liên tục và sau vị trí đó có dãy tăng dài nhất không liên tục

----
Với input:
10
1 2 3 4 2 5 1 2 3 4
ta có LDS (dãy giảm không liên tục từ trái sang phải):
1 1 1 1 2 1 3 2 2 2
và LIS (dãy giảm không liên tục từ phải sang trái)
5 4 3 2 3 1 4 3 2 1
=> ta thấy được tại vị trí a[6] có:
LDS[6] = 3 (tức trước vị trí đó 3 (tính cả ngay tại a[6]) phần tử giảm dần không liên tục)
LIS[6] = 4 (tức sau vị trí đó 4 (tính cả ngay tại a[6]) phần tử tăng dần không liên tục)
longestLom = 3 + 4 - 1 (trừ đi 1 vì trùng tại a[6]) = 6
*/


int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Tìm dãy giảm dài nhất (LDS) từ trái sang phải
    for (int i = 0; i < N; i++)
    {
        LDS[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[i] && LDS[i] < LDS[j] + 1)
            {
                LDS[i] = LDS[j] + 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ",LDS[i]);
    printf("\n");
    // Tìm dãy tăng dài nhất (LIS) từ phải sang trái
    for (int i = N - 1; i >= 0; i--)
    {
        LIS[i] = 1;
        for (int j = N - 1; j > i; j--)
        {
            if (A[j] > A[i] && LIS[i] < LIS[j] + 1) //A[j] > A[i] tức là dãy đang giảm từ phải sang trái
            {
                LIS[i] = LIS[j] + 1; //cập nhật lại nếu LIS[i] < LIS[j]
            }
        }
    }
    for (int i = 0; i < N; i++)
        printf("%d ",LIS[i]);

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
        printf("\n%d\n", maxLomLength);
    }

    return 0;
}
