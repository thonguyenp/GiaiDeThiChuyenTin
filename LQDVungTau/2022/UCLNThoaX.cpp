#include<stdio.h>

int UCLN (int a, int b)
{
    if (b == 0) return a;
    if (a % b == 0) return b;
    else return UCLN (b,a%b);
}

int main ()
{
    long long a, b;
    scanf("%lld%lld",&a,&b);

    for (int i = 1; i <= (a > b) ? a : b; i++)
    {
        if (UCLN(a+i,b+i) == b-a)
        {
            printf("%d",i);
            break;
        }
    }
}