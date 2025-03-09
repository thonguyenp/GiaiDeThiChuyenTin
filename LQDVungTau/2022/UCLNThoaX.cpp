#include<stdio.h>


int UCLN (int a, int b)
{
    if (b == 0) return a;
    if (a % b == 0) return b;
    else return UCLN (b,a%b);
}

//c2: dùng tính chất của ucln
/*
Ta có: ucln(a,b) = d 
=> a%d == 0 và b%d == 0 thì (a - b) % d = 0 => d là UCLN của (a-b)
=> ucln(a,b) = ucln(a-b,b) = ucln(a,a-b) = d (1)
đề bài yêu cầu tìm x sao cho ucln(a+x,b+x) = b-a
=> vế trái ucln ((a+x)-(b+x),b+x) = ucln (a-b,b+x) =>ucln (a-b,b+x) = b-a (2)
(ucln (a-b,b+x) = ucln (b-a,b+x))
=> từ đề bài thành tìm b-a sao cho a-b chia hết b+x (hoặc b+x chia hết cho b-a)
=> tồn tại 1 số k sao cho (b+x) / (b-a) = k => ta có: b+x≡0 theo (b-a) => x≡-b -> -b chia hết cho  b-a => -b % (b-a) = 0

Ta cá: b = q(b-a) + r (q là thương, r là dư (r = b %(b-a))) => -b = -q(b-a) - r => -b%(b-a) = (-q(b-a) -r) % (b-a) (modulo hai vế)
=> -b %(b-a) = (-q(b-a)%(b-a) - r % (b-a)) (mà: -q(b-a)%(b-a) = 0) => -b %(b-a) = -r % (b-a)
Vì -r % (b-a) có thể là 1 số âm, ta công thêm (b-a) và r => -b %(b-a) = (b-a-r) % (b-a) (cộng được vì b-a chia hết cho b-a => phương trình không đổi)
Mà r = b % (b-a) => x = (b-a - (b%(b-a)) % b-a)
*/
long long solve(long long a, long long b) {
    long long d = b - a;
    return (d - (b % d)) % d;
}

int main ()
{
    long long a, b;
    scanf("%lld%lld",&a,&b);
    //c1: vét cạn
    for (int i = 1; i <= (a > b) ? a : b; i++)
    {
        if (UCLN(a+i,b+i) == b-a)
        {
            printf("%d",i);
            break;
        }
    }
    printf("\n%lld",solve(a,b));
    
}