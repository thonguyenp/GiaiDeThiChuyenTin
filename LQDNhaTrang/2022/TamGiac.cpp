#include<stdio.h>
#define countMax 2000
void TimBoBaPTUBangNhau (int a[], int n)
{
    int count[countMax] = {0};
    //duyet het mang a, tinh so lan nhap cua cac gia tri trong mang, luu vao mang count
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    // for (int i = 0; i < countMax; i++)
    // {
    //     printf("%d",count[i]);
    // }
    int x = 0, y = 0;
    //duyet het mang count, tinh so tam giac va canh thua
    for (int i = 0; i < countMax; i++)
    {   
        //nhap 5 lan so 1 => 1 tam giac co kich thuoc la 1 va du lai 2 que
        x += count[i] / 3;
        y += count[i] % 3;
    }
    printf("%d %d",x,y);
}

int main ()
{
    int n = 8; 
    // scanf("%d",&n);
    int a[n] = {1,2,6,6,1,1,2,1};
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d",&a[i]);
    // }
    TimBoBaPTUBangNhau(a,n);
}