#include<stdio.h>

//Tìm Thừa SNT nhỏ nhất của 1 số
int ThuaSNTNhoNhat (int n)
{
    if (n < 2) return -1;
    if (n % 2 ==0) return 2;
    for (int i = 3; i * i <= n; i+=2)
        if (n % i == 0) return i; //trả về snt đầu tiên tìm được
    return n; //n chính là 1 số nguyên tố
}

int main ()
{
    long long n, k;
    scanf("%lld%lld",&n,&k);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);  //a[i] ở đây mặc định là số nguyên tố
    int res[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (ThuaSNTNhoNhat(j) == a[i])  //nếu thừa số ngto của j bằng với số a[i]
                res[i]++;   //res ở vị trí 1 tăng thêm 1
        }
    }
    
    for (int j = 0; j < n; j++)
        printf("%d\n",res[j]);
}