#include<stdio.h>

int TongChuSo (int n)
{
    /*
    vào vòng lặp 1
    Vd: 76 => còn ít nhất 2 chữ số => sum = 6, n = 7
    7 => còn 1 chữ số => sum = 6 + 7 = 13, n = 0
    hết vòng lặp 2

    vào vòng lặp 1
    gán sum cho n => n = 13
    13 => còn ít nhất 2 chữ số => sum = 3, n = 1
    1 => còn 1 chữ số => sum = 3 + 1 = 4, n = 0
    hết vòng lặp 2

    4 => còn 1 chữ số => in ra kết quả
    */
    while (n >= 10) //khi n vẫn còn 2 chữ số
    {
        int sum = 0;    //khởi tạo sum
        while (n > 0)   //khi n vẫn còn 1 chữ số
        {
            sum += n%10;    //cộng dồn từng chữ số của n cho sum
            n /= 10;    //n chia nguyên cho 10 để mất 1 chữ số
        }
        n = sum;    //kết thúc vòng lặp 2 thì gán lại sum cho n
    }
    return n;
}

int DigitalRoot(int n) {
    if (n == 0) return 0;
    return 1 + (n - 1) % 9;
}

int main ()
{
    int a,b;
    scanf("%d%d",&a,&b);
    // printf("%d",TongChuSo(76));
    int s = 0;
    for (int i = a; i <= b; i++)
    {
        // s += TongChuSo(i);
        s += DigitalRoot(i);
    }
    printf("%d",s);
}