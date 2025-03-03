#include<stdio.h>
void swap (int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Descending (int a[], int n)
{
    for (int i = 0; i < n -1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j]) swap(a[i],a[j]);
}

void MaxChuVi (int a[], int n)
{
    Descending(a,n);
    int found = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] + a[i + 1] > a[i + 2])
        {
            printf("%d %d %d", a[i],a[i+1],a[i+2]);
            found = 1;
            break;
        }
    }
    printf("%d",found);

}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);

    //Kiến thức cần có:sắp xếp mảng +  kiểm tra điều kiện tam giác
    MaxChuVi(a,n);
}