#include<stdio.h>
#include<math.h>

float BieuThucA (int n)
{
    float s = 0;
    for (int i = 3; i <= n; i++)
    {
        s += (float)(i-1)/i;
    }
    return s;
}

float BieuThucB (int n)
{
    float s = 0;
    for (int i = 1; i <= n; i++)
        s += ((float)1/pow(3,(2*i)-1) - (float)1/pow(3,2*i));
    return s;
}

int main ()
{
    int n;
    scanf("%d",&n);
    printf("%.2f",BieuThucA(n));
    printf("\n%.2f",BieuThucB(n));
}