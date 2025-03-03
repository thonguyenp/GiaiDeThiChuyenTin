#include<stdio.h>

int XepTao(char a[], int n)
{
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        // Dạng 1: xen kẽ "010101..."
        if (i % 2 == 0 && a[i] != '0') count1++; // Vị trí chẵn phải là '0'
        if (i % 2 == 1 && a[i] != '1') count1++; // Vị trí lẻ phải là '1'

        // Dạng 2: xen kẽ "101010..."
        if (i % 2 == 0 && a[i] != '0') count2++; // Vị trí chẵn phải là '1'
        if (i % 2 == 1 && a[i] != '1') count2++; // Vị trí lẻ phải là '0'
    }
    return (count1 < count2) ? count1 : count2;

}

int main ()
{
    int n;
    scanf("%d",&n);
    char a[2*n];
    fflush(stdin);
    scanf("%s",a);
    printf("%d",XepTao(a,n));
}