#include<stdio.h>
#include<string.h>

void CongKhongNho (char n[], char k[], char res[])
{
    for (int i = strlen(n) - 1; i >= 0; i--)
    {
        int n1 = n[i] - '0'; //chuyển về số
        int n2 = k[i] - '0';
        int s = (n1 + n2) % 10; //chỉ lấy số đơn vị
        res[i] = s + '0';
    }
    res[strlen(res)] = '\0';
}

int main ()
{
    char n[15],k[15],res[15];
    scanf("%s",n);
    scanf("%s",k);
    CongKhongNho(n,k,res);

    int i = 0;
    //duyệt tiếp chưa duyệt hết số 0 và kí tự sau không phải null
    while (res[i] == '0' && res[i + 1] != '\0') i++;  

    printf("%s",res + i);
}