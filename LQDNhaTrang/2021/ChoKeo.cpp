#include<stdio.h>

int main ()
{
    int a,b,k,x,y;
    scanf("%d%d%d%d%d",&a,&b,&k,&x,&y);
    int keoCamDaAn = a * k - x;
    int keoXanhDaAn = b * k - y;
    if (keoCamDaAn % 2 ==0) printf("%d ",keoCamDaAn / 2);
    else printf("%d ",keoCamDaAn / 2 + 1);
    if (keoXanhDaAn % 2 ==0) printf("%d",keoXanhDaAn / 2);
    else printf("%d",keoXanhDaAn / 2 + 1);

}