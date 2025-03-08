#include<stdio.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Descending (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) swap(a[i], a[j]);
}

int ContainZero (int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] == 0) return 1;
    return 0;
}

int SortDigitsDes (int n)
{
    int digit[6], count = 0;    //khởi tạo mảng và biến đếm số phần tử
    while (n > 0)   //lấy các kí số đưa vào mảng
    {
        digit[count++] = n % 10;
        n /= 10;
    }

    Descending(digit,count);
    int res = 0;
    if (n % 3 == 0 && ContainZero(digit,count))
    {
        for (int i = 0; i < count; i++)
        {
            res = res * 10 + digit[i];
        }
        return res;
    }
    else 
        return -1;
}

// nếu tổng chữ số chia hết cho 3 và có số 0
// => sắp xếp các chữ số giảm dần
int main ()
{
    int n;
    scanf("%d", &n);
    printf("%d",SortDigitsDes(n));
}