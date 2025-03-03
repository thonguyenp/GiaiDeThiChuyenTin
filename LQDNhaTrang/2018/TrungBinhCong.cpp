#include<stdio.h>

float TongChuSo (long long k)
{
    int s = 0, c = 0;
    long long temp = k;
    while (temp > 0)
    {
        s += temp % 10;
        temp /= 10;
        c++;
    }
    return (float)s/c;
}

int main()
{
    long long k;
    
    scanf("%lld",&k);
    printf("%.2f",TongChuSo(k));
}