#include<stdio.h>



int main ()
{
    long long n;
    char m;
    scanf("%d%lld",&m,&n);
    printf("%lld",(m + n) % 60);
}