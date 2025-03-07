#include<stdio.h>

int main ()
{
    long long n, k;
    scanf("%lld%lld",&n,&k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);  //a[i] ở đây mặc định là số nguyên tố
    int res[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (j % a[i] == 0)
                res[i]++;
        }
    }

    for (int j = 0; j < n; j++)
        printf("%d\n",res[j]);
}