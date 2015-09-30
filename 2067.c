#include <stdio.h>
#include <math.h>
int prime(num)
{
    if (num==0 || num == 1)
        {
            return 0;
        }
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int num;
    int max = 0;
    scanf("%d", &num);
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0 && prime(i) == 1 && prime(num / i) == 1 && i > max)
        {
            if (i > num /i)
            {
                max = i;
            }
            else
            {
                max = num /i;
            }
            break;
        }
    }
    printf("%d\n", max);
}
