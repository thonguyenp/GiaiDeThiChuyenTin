#include<stdio.h>

int main ()
{
    unsigned long n;
    scanf("%lu", &n);

    char str[n+1];
    scanf("%s", str);

    unsigned long countAA = 0, countBB = 0;
    unsigned long extraAA = 0, extraBB = 0;
    int hasStar = 0;

    for (unsigned long i = 0; i < n - 1; i++)
    {
        if (str[i] == 'A' && str[i+1] == 'A')
            countAA++;
        else if (str[i] == 'B' && str[i+1] == 'B')
            countBB++;
        if (str[i] == '*' || str[i + 1] == '*')
            hasStar = 1;    //bật cờ lên
    }

    //Thop 1: ko có sao
    if (hasStar == 0)
    {
        if (countAA > countBB)
            printf("%d", countAA);
        else
            printf("%d", countBB);
    }
    //thop 2: có sao
    else
    {
        for (unsigned long i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                //kiểm tra kí tự trước sao
                if (i > 0)
                {
                    if (str[i - 1] == 'A') extraAA++;
                    if (str[i - 1] == 'B') extraBB++;
                }
                //kiểm tra kí tự sau sao
                if (i < n - 1)
                {
                    if (str[i + 1] == 'A') extraAA++;
                    if (str[i + 1] == 'B') extraBB++;
                }
            }
        }
        if (countAA + extraAA > countBB + extraBB)
        {
            printf("%lu", countAA + extraAA);
        }
        else
        {
            printf("%lu", countBB + extraBB);
        }
    }
}