#include<stdio.h>
#include<math.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Descending (int a[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n; j++)
            if (a[i] < a[j]) swap(a[i],a[j]);
}

int SoLanCan (int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) s += abs(a[i] - a[i + 1]);  //nếu là số đầu => trừ cho số phía sau
        else if (i == n - 1) s += abs(a[i-1] - a[i]);   //nếu là số cuối => trừ cho số phía trước
        else    //nếu là số chính giữa
        {
            if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1]))    //nếu hiệu giữa nó và số liền sau nhỏ hơn hiệu giữa nó và số liền trước
                s += abs(a[i] - a[i + 1]);  //lấy hiệu giữa nó và số liền sau
            else 
                s += abs(a[i] - a[i - 1]);  //lấy hiệu giữa nó và số liền trước
        } 
    }
    return s;
}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    Descending(a,n);    //sắp xếp mảng giảm dần
    printf("%d",SoLanCan(a,n));
}