#include<stdio.h>
#include<stdlib.h>

void swap (long long &a, long long &b)
{
    int t = a;
    a = b;
    b = t;
}

void Ascending (long long a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n;j++)
            if (a[i] > a[j]) swap(a[i],a[j]);

}

int compare(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);   //ép kiểu 2 con trỏ void thành long long 
    //kết quả âm => a < b => tăng dần
    //kết quả dương => a > b => giảm dần
}


int main ()
{
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    long long a[n];
    for (int i = 0; i < n; i++)
        scanf("%lld",&a[i]);

    //c1: O(n^2)
    // int count = 0;
    // for (int i = 0; i < n - 1; i++)
    //     for (int j = i + 1; j < n;j++)
    //         if (a[i] + a[j] == k) count;
    // printf("%d",count);

    //c2: sắp xếp mảng, sau đó dùng 2 con trỏ
    // Ascending(a,n);
    qsort(a, n, sizeof(long long), compare); // Sắp xếp mảng O(n log n)

    int left = 0, right = n-1, count = 0;
    while (left < right)
    {
        if (a[left] + a[right] == k)
        {
            count++;
            left++;
            right--;
        }
        else if (a[left] + a[right] < k) left++;    //tổng bé hơn k => tăng biên trái để số lớn hơn
        else right--;   //tổng lơn hơn k => giảm biên phải để số bé hơn
    }
    printf("%d",count);
}