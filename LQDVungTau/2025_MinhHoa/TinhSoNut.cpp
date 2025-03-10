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
/*
Cách 2: 1 số N hệ 10 có thể được viết là: N = a(K+1) * 10^(K+1) + ... + a1 * 10 ^1 + a0 * 10^0 (k biểu thị cho số a là chữ số hàng nào)
vd: 123 = 1*100 + 2*10 + 3+10^0
Giả sử: N = a(K+1)a(K)a(K-1) => Ta lại có: S(N) = a(K+1) + a(K) + a(K-1) 
vd: 123 = 1 + 2 + 3
=> Kết quả của n%9 bằng tổng các chữ số của n chia lấy dư cho 9
=> Vd: 123 % 9 = 6, 1+2+3 = 6 % 9 = 6
=> Số nút của 1 số sẽ là số đó chia lấy dư cho 9
Lại có vấn đề: Nút của những số chia hết cho 9 sẽ bằng 9, nhưng nếu dùng công thức trên sẽ bằng 0
=> Ta lấy n trừ cho 1 để chia dư 9 còn 8, sau đó lấy kết quả cộng thêm 1 => công thức cuối cùng là: 1 + (n-1) % 9
 */
int DigitalRoot(int n) {
    if (n == 0) return 0;
    // return 1 + (n - 1) % 9;
    return n % 9;
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
    // printf("%d",DigitalRoot(17));
}