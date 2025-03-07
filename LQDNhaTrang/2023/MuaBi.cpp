#include<stdio.h>

int main ()
{
    long long n;
    int a,b;
    int count = 0;
    scanf("%lld%d%d",&n,&a,&b);
    char arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        if (arr[i] == 2) count++;
    }            
    int min = (a < b) ? a : b;
    int max = (a > b) ? a : b;
    printf("%d",min*n + count * max);
}