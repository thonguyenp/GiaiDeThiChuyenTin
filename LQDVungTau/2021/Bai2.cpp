#include<stdio.h>
#include<string.h>
#include<math.h>

void XoaSo0 (long long n, char str[])
{
    sprintf(str, "%lld",n); //Quan trọng: thay vì đưa kết qua của n ra màn hình như printf thì đưa kết quả vào chuỗi str
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '0') printf("%c",str[i]);
    }
}

int main ()
{
    long long n;
    char str[20];
    scanf("%lld",&n);

    int a;
    scanf("%d",&a);
    XoaSo0(n,str);  //bài 1
    printf("\n");
    printf("%lld",(long long)pow(a,n) % 10); //bài 2
}