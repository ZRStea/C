#include <stdio.h>
int prime(num)
{
    if (num==0 || num == 1)
        {
            return 0;
        }
    for (int i = 2; i < num; ++i)
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
    int all;
    int maxprime = 0;
    int max = 1;
    int num;
    scanf("%d", &all);
    for (; all>0; --all)
    {
        scanf("%d", &num);
        // printf("%d\n", num);
        for (int i =2; i<=num; ++i)
        {
            if (num % i == 0 && prime(i) == 1 && i >= maxprime)
            {
                maxprime = i;
                max = num;
            }
        }
    }
    printf("%d\n", max);
}