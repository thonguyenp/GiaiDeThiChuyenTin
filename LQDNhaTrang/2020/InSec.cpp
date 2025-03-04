#include<stdio.h>

//Kiểm tra số có chữ số 4 trong không
int isValid (int n)
{
    while (n > 0)
    {
        if (n % 10 == 4) return 0;
        n /= 10;
    }
    return 1;
}

int main ()
{
    int d;
    scanf("%d",&d);
    for (int i = d/2; i >= 0; i--)  //dò i từ vị trí d/2 cho 0
    {
        int j = d - i;  //cho j tăng ngược từ d/2 -> d
        if (isValid(i) && isValid(j))
        {
            printf("%d %d", i,j);
            break;
        }
    }

}