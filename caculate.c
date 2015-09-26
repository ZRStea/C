#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
char plus[2000];
int pl()
{
    int length1;
    int length2;
    length2 = strlen(num2);
    length1 = strlen(num1);
    if (length1>=length2)
    {    }
    else
    {
        int t;
        t = length2;
        length2 = length1;
        length1 = t;
    }
    int temp,n = 0;
    for (; length1>=1; )
    {
        if (length2 >=1)
        {
            temp = (num1[length1-1] + num2[length2-1] + n) - 96;
            // printf("%d\n", temp);
            if (temp < 10)
            {
                plus[length1] = (char) (temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                plus[length1] = (char) (temp + 38);
            }
        --length2;
        --length1;
        }
        else
        {
            temp = (num1[length1-1] + '0' + n) - 96;
            if (temp < 10)
            {
                plus[length1] = (char) (temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                plus[length1] = (char) (temp + 38);
            }
        --length1;
        }
    }
    if (n == 1)
    {
        plus[0] = '1';
    }
    else
    {
        for(int i=0; i<=strlen(plus)+1; ++i)
        {
           plus[i] = plus[i+1]; 
        }

    }
    return 0;
}

int main()
{
    scanf("%s",num1);
    scanf("%s",num2);
    pl();
    printf("%s\n",plus);
    // puts(num1);
    // puts(num2);
    // printf("%d\n",length2);
    // printf("%d\n",length1);
    return 0;
}