#include<stdio.h>

int main ()
{
    //Tính chi phí để gắn được nhiều bóng đèn nhất
    //Số cây có thể là chẵn hoặc lẻ
    //Nếu là chẵn
    //1 2 3 4 5 6
    // x 0 x 0 x 0
    // 0 x 0 x 0 x
    // => như nhau => (n / 2) * x
    //Nếu là lẻ
    // 1 2 3 4 5 
    // 0 x 0 x 0
    // x 0 x 0 x
    //=> Cách trang trí ở đầu sẽ tối ưu hơn => (n / 2 + 1) * x
    long long n;
    int x;
    scanf("%lld%d",&n,&x);
    printf("%d",(n % 2 == 0) ? (n / 2 * x) : ((n / 2 + 1) * x));
    printf("%d", 5%2);
}