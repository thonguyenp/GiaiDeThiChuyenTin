#include<stdio.h>

int KtraSNT (int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i<= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int TongCacChuSo (int n)
{
    int tmp = n;
    int s = 0;
    while (tmp > 0)
    {
        s += tmp%10;
        tmp /= 10;
    }
    return s;
}

void SNTDB (int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (KtraSNT(i) && KtraSNT(TongCacChuSo(i)))
            printf("%d ",i);
    }
}

int main ()
{
    int l,r;
    scanf("%d%d",&l,&r);
    // printf("%d",TongCacChuSo(67));
    SNTDB(l,r);
}