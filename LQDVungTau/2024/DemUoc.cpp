#include<stdio.h>

//Ta có n = a * b thì a và b sẽ là 1 cặp ước của n
// => a = n / b => n = (n/b) * b => b và n/b sẽ là 1 cặp ước gồm ước số lớn và ước số nhỏ của n
//Nhưng bên cạnh đó,sẽ có trường hơp b = n / b (vd: 3 = 9 / 3) => chỉ đếm các ước có điều kiện là (i != n/i)
int DemUoc (long long n)
{
    int s = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) 
        {
            s++;
            if (i != n/i)
                s++;
        }
    }
    return s;
}

int main ()
{
    long long n;
    scanf("%lld",&n);
    printf("%d",DemUoc(n));
    return 0;
}