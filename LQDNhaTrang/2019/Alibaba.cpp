#include<stdio.h>

int main ()
{
    int n, d;
    scanf("%d%d",&n,&d);
    //giải hệ phương trình    
    // vang = bac - d
    // bac = dong - d => dong = vang - 2d
    // vang + bac + dong = n
    // dong - 2d + dong - d + dong = n
    // 3dong - 3d = n => dong = n/3 + d
    int dong = n/3 + d;
    int bac = dong - d;
    int vang = bac - d;
    if (vang + bac + dong == n && vang >=0 && bac >=0 && dong >=0)
    {
        printf("%d %d %d", vang, bac, dong);
    }
    else
        printf("%d",-1);
}