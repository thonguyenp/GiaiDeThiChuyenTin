#include<stdio.h>

int LaSNT (int n)
{
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    // Kiểm tra các số dạng 6k ± 1 từ 5 đến √n
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;

}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if ((a[i] - 2) / 5 == (float)(a[i] - 2) / 5) printf("%d ",a[i]);   //câu a
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        if (LaSNT(a[i])) printf("%d ",a[i]);
}