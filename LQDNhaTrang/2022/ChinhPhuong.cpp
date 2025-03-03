#include<stdio.h>

int laSCP (int n)
{
    if (n <= 0) return 0;
    int i = 0;
    while (i * i <= n)
    {
        if (i * i == n) return 1;
        i++;
    }
    return 0;
}

int DemSCP (int x, int y)
{
    int s = 0;
    for (int i = x; i <= y; i ++)
    {
        if (laSCP(i)) s++;
    }
    return s;
}

int main ()
{
    int x, y;
    scanf("%d%d",&x,&y);
    printf("%d",DemSCP(x,y));
    // printf("%d",laSCP(4));
}