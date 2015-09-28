#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
char rlt[2000];
int pl()
{
    int length1;
    int length2;
    length2 = strlen(num2);
    length1 = strlen(num1);
    if (length1 >= length2)
    {
    }
    else
    {
        char numt[2000];
        int t;
        t = length2;
        length2 = length1;
        length1 = t;
        strcpy(numt, num2);
        strcpy(num2, num1);
        strcpy(num1, numt);
    }
    int temp, n = 0;
    for (; length1>=1; )
    {
        if (length2 >= 1)
        {
            temp = (num1[length1-1] + num2[length2-1] + n) - 96;
            // printf("%d\n", temp);
            if (temp < 10)
            {
                rlt[length1] = (char)(temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                rlt[length1] = (char)(temp + 38);
            }
            --length2;
            --length1;
        }
        else
        {
            temp = (num1[length1-1] + '0' + n) - 96;
            if (temp < 10)
            {
                rlt[length1] = (char)(temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                rlt[length1] = (char)(temp + 38);
            }
            --length1;
        }
    }
    return 0;
}

int minus()
{
    int length1;
    int length2;
    length2 = strlen(num2);
    length1 = strlen(num1);
    if (length1 >= length2)
    {
    }
    else
    {
        char numt[2000];
        int t;
        t = length2;
        length2 = length1;
        length1 = t;
        strcpy(numt, num2);
        strcpy(num2, num1);
        strcpy(num1, numt);
    }
    int temp,n = 0;
    for (; length1>=1; )
    {
        if (length2 >= 1)
        {
            temp = (num1[length1-1] - num2[length2-1] - n);
            // printf("%d\n", temp);
            if (temp >= 0)
            {
                rlt[length1] = (char)(temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                rlt[length1] = (char)(temp + 58);
            }
            --length2;
            --length1;
        }
        else
        {
            temp = (num1[length1-1] - '0' - n);
            if (temp >= 0)
            {
                rlt[length1] = (char)(temp + 48);
                n = 0;
            }
            else
            {
                n = 1;
                rlt[length1] = (char)(temp + 58);
            }
            --length1;
        }
    }
    for(int i=0; i<=strlen(rlt)+1; ++i)
    {
        rlt[i] = rlt[i+1]; 
    }
    for (; rlt[0] == '0'; )
    {
        for(int i=0; i<=strlen(rlt)+1; ++i)
        {
            rlt[i] = rlt[i+1]; 
        }
    }
    if (rlt[0] == 0)
    {
        rlt[0] = '0';
    }
    return 0;
}

int main()
{
    scanf("%s",num1);
    scanf("%s",num2);
    minus();
    printf("%s\n",rlt);
    // puts(num1);
    // puts(num2);
    // printf("%d\n",length2);
    // printf("%d\n",length1);
    return 0;
}

