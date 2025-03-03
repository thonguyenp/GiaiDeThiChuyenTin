#include<stdio.h>

void PhanTichSo (long long n)
{
    //Vì 1 số chẵn thì không tách được thành 2 số lẻ => n lẻ thì return -1
    if (n % 2 == 1) printf("-1");
    else
    {
        //set a và b ở trường hợp (2)
        long long a = n / 2 + 1;
        long long b = n / 2 - 1;
        if (a % 2 == 0)     //nếu a là số chẵn
        {   
            a = b = n/2;    //đưa a và b vào trường hợp (1)
            printf("%lld %lld",a,b);
        }
        else
            printf("%lld %lld",a,b);
    }
}

int main ()
{
    long long n;
    scanf("%lld",&n);
    //Cốt lõi của bài toán:
    // Vì a và b đều là số lẻ, và a > =b => a - b = 0 (1) V a - b = 2 (2)
    //Từ (2) ta có hệ sau
    // a - b = 2
    // a + b = n

    // 2a = 2 + n
    // a = n/2 + 1
    // => b = a - 2 = n/2 - 1
    //Từ (1) ta có hệ sau:
    //a = b
    //a + b = n => a = b = n/2
    PhanTichSo(n);
    
}