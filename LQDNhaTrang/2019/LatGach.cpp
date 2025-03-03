#include<stdio.h>

int main ()
{
    //diện tích 1 viên gạch là 2dm^2 => diện tích nửa viên gạch 1dm^2
    //tính số viên gạch còn dư
    int n, d;
    scanf("%d%d",&n,&d);

    //cách 1: diện tích sân là n * d => nếu là số chẵn thì không dư, nếu là số lẻ thì dư 1 viên
    //=> dùng phép tính lấy phần dư
    printf("%d",n * d % 2); 
}