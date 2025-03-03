#include<stdio.h>
#include <stdlib.h>

void swap (int &a, int &b)
{
    int t = a;
    a =b;
    b = t;
}

void Ascending(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
            if (a[i] > a[j]) swap(a[i],a[j]);
    }
}
int TimSoDiaToiDa(int a[], int n) {
    Ascending(a,n); //sắp xếp dãy tăng dần
    // for (int i = 0; i < n; i++)
    //     printf("%d",a[i]);
    int count = 0; // Số đĩa xếp lên nhau
    for (int i = 0; i < n; i++) //duyệt hết mảng độ bền các dĩa
    {
        if (a[i] >= count) //nếu nếu
        { 
            count++; // Thêm đĩa này vào cuối chồng
        } else {
            break; // Nếu vượt quá độ bền của đĩa này thì dừng lại
        }
    }
    return count;
}


int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("%d",TimSoDiaToiDa(a,n));
}