#include<stdio.h>

/*
Trong bài toán, x là bội số của k
Ta có x thỏa: x = k * m (m là số dương) thì x là bội số của k
vd: bội số của 3 là: 3, 6, 9, ... có dạng là 3k (k= 1, 2, 3, ...)
=> tìm số lượng bội số trong đoạn [1,b] chính là tìm m trong x = k * m 
=> m = x / k => lấy phần nguyên của công thức này
------
Phép hiệu để tìm ra được bội số của k trong [a,b]
(b/k) - ((a-1)/k) = (b-a+1) / k
Dùng a-1 thay vì a, vì nếu a là bội số của k thì khi tính phép sẽ bị mất đi a

*/
int main ()
{
    long long a,b,k;
    scanf("%lld%lld%lld",&k,&a,&b);
    //cách 1
    int c = 0;
    for (int i = a; i <= b; i++)
    {
        if(i % k == 0) c++;
    }
    printf("%d\n",c);
    //cách 2
    long long result = (b-a+1)/k;
    printf("%lld",result);
}