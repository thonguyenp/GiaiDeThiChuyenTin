#include<stdio.h>

void swap (int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void Ascending (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) swap(a[i], a[j]);
}

int DemPhanTuTrung (int a[], int n)
{
    int c = 0, j = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            c++;
            // Bỏ qua tất cả các phần tử trùng tiếp theo
            while (i < n - 1 && a[i] == a[i + 1]) { 
                i++;
            }
        }
    }
    return c;
}

int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    Ascending(a,n);
    printf("%d",DemPhanTuTrung(a,n));
}