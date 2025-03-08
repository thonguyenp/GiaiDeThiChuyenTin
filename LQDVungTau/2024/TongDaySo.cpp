#include<stdio.h>


int main ()
{
    //input
    long long n, k, p;
    scanf("%lld%lld%lld",&n,&k,&p);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    
    int s = 0;
    //vì là dãy lặp => vị trí bắt đầu sẽ là vị trí đưa vào chia lấy dư cho số phần tử
    int pos = (p % n) - 1;
    //duyệt từ pos đến k số liên tiếp trong dãy
    for (int i = pos; i < (pos + k); i++)
        // Vị trí thì chia lấy dư cho số phần tử để lặp lại trong dãy
        s += a[i % n];
    printf("%d",s);
}