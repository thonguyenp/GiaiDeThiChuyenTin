#include<stdio.h>

int main ()
{
    unsigned long long a, b;
    scanf("%llu%lld",&a, &b);

    printf("%llu", (a + b / 3) + 1);
    
}