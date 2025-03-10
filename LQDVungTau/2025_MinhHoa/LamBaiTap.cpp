#include<stdio.h>
#include<stdlib.h>

int cmp (const void *a, const void *b)
{
    return(*(int*)a) - (*(int*)b);
    
}

int main ()
{
    int n, t;
    scanf("%d%d",&n,&t);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    // qsort(a,n,sizeof(int),cmp);

    int left = 0, right = 0, maxCount = 0, sum = 0;
    /*
    Sử dụng thuật toán sliding window
    1. tăng dần biên phải cộng thêm gtri bên phải
    2. đến khi sum > t thì tăng biên trái, sau đó trừ giá trị bên trái, cập nhật lại count
    3. cập nhập lại maxCount sau mỗi lần giảm
    4. tăng biên phải lên
    
    */
    while (right < n)
    {
        sum += a[right];
        while (sum > t)
        {
            sum -= a[left];
            left++;
        }
        int count= right - left + 1;
        if (count > maxCount)
            maxCount = count;
        right++;
    }
    printf("%d",maxCount);
}