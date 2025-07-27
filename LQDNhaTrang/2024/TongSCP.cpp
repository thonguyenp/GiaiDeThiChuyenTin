#include<stdio.h>
#include<math.h>

int laSCP (unsigned long long n)
{
    unsigned long long sqr = sqrt(n);
    if (sqr * sqr == n)
        return 1;
    else 
        return 0;
}



int main ()
{
    unsigned long n;
    scanf("%lu", &n);
    
    unsigned long long x[n];
    unsigned long long sum[n];
    unsigned long count[n];

    for (unsigned long i = 0; i < n; i++)
        scanf("%llu", &x[i]);
    
    for (unsigned long i = 0; i < n; i++)
    {
        count[i] = 0;
        sum[i] = 0;
        for (unsigned long long j = 1; j < x[i]; j++)
        {
            if (laSCP(j))
            {
                sum[i] += j;
                if (sum[i] <= x[i])
                {
                    count[i]++;
                }
            }
        }
        printf("%lu ", count[i]);
    }
}