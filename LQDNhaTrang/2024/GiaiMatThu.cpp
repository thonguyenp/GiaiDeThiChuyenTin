#include <stdio.h>
#include <string.h>

int countChar(char c, char str[])
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c && str[i + 1] == c)
            count++;
    }
    return count;
}

int containStar(char str[])
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '*')
            return 1;
    return 0;
}

int main()
{
    int n;
    char str[n];
    scanf("%d", &n);
    scanf("%s", &str);

    if (containStar(str))
    {
        /*
        Tính số lần thay đổi khi có *
        5 thop:
        *A, A*, *B, B*, **

        */
        int extraAA = 0, extraBB = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '*' && str[i + 1] == 'A')
                extraAA++;
            if (str[i] == 'A' && str[i + 1] == 'B')
                extraAA++;
            if (str[i] == '*' && str[i + 1] == 'B')
                extraBB++;
            if (str[i] == 'B' && str[i + 1] == '*')
                extraBB++;
            if (str[i] == '*' && str[i + 1] == '*')
            {
                extraAA++;
                extraBB++;
            }
        }
        /*
            sau đó tính extraAA/BB + countAA/BB và so sánh
            Nếu cái nào lớn hơn thì gán vào result
        */
        int countAA = countChar('A', str);
        int countBB = countChar('B', str);
        int result;
        if (countAA + extraAA > countBB + extraBB)
        {
            result = countAA + extraAA;
        }
        else
        {
            result = countBB + extraBB;
        }
        printf("%d\n", result);
    }
    else
    {
        if (countChar('A', str) > countChar('B', str))
        {
            printf("%d", countChar('A', str));
        }
        else
        {
            printf("%d", countChar('B', str));
        }
    }
    printf("\nString is %s", str);
}