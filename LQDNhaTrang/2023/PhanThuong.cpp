#include<stdio.h>

void swap (int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Descending (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) swap(a[i],a[j]);
}

int TimMin (int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (min > a[i]) min = a[i];
    }
    return min;
}

int main ()
{
    int m,n;
    scanf("%d%d",&m,&n);
    int a[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
    }
    Descending(a,m);
    
    
    if (n < m)
    {
        printf("%d",a[n-1] * n);
    }
    else
    {
        printf("%d",TimMin(a,n) * n);
    }
    
}