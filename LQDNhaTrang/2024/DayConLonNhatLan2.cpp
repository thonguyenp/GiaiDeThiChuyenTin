#include<stdio.h>

int main ()
{
    unsigned long n, k;
    
    scanf("%lu %lu", &n, &k);

    long long a[n + 1];
    for (long i = 1; i <= n; i++)
    {
        scanf("%llu", &a[i]);
    }

    //Kiểm tra cửa sổ đầu tiên
    long long sum = 0;
    long evenCount = 0; 
    for (long i = 1; i <= k; i++)
    {   
        sum += a[i];
        if (a[i] % 2 == 0) evenCount++;
    }

    long long maxSum = sum;
    long maxCount = evenCount;
    long start = 1;
    long end = k; 
    //Truợt tiếp các cửa sổ tiếp theo
    for (long i = 2; i < n - k + 1; i++)
    {
        sum = sum - a[i - 1] + a[i + k - 1];
        long newCount = evenCount;
        if (a[i - 1] % 2 == 0) newCount--;
        if (a[i + k - 1] % 2 == 0) newCount++;

        if (sum > maxSum ||
            (sum == maxSum && newCount > maxCount) ||
            (sum == maxSum && newCount > maxCount && i < start))
        {
            maxSum = sum;
            maxCount = evenCount;
            start = i;
            end = i + k - 1;
        }
        evenCount = newCount;
    }
    printf("%lu %lu", start, end);
}