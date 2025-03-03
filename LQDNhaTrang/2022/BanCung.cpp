#include<stdio.h>

int UCLN (int a, int b)
{
    return (b == 0) ?  a : UCLN(b, a % b);
}

int BCNN (int a, int b)
{
    return (a/UCLN(a,b)) * b; //bcnn = a * b / UCLN
}

int TimBCNN (int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        max = BCNN(max,a[i]);
    }
    return max;
}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",TimBCNN(a,n));
}