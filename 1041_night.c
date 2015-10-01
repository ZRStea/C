#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
char rlt[2000];
char temp[2000];
char expression[2000];
char status;
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
    scanf("%s", expression);
    int i = 0;
    for (int t = 0; ; ++t)  //读取num1
    {
        if (expression[i] == '+' || expression[i] == '-')
        {
            break;
        }
        num1[t] = expression[i];
        ++i;
        printf("a %d\n",i);
    }
    status = expression[i];
    ++i;
    for (int t = 0; ; ++t)  //读取num2
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == 0)
        {
            break;
        }
        num2[t] = expression[i];
        ++i;
        printf("b %d\n",i);
    }
    if (status == '+')
    {
        pl();
    }
    if (status == '-')
    {
        minus();
    }
    for (; ; )
    {
        if (expression[i] == '\0')
        {
            break;
        }
        status = expression[i];
        ++i;
        printf("c %d\n",i);
        strcpy(num1, rlt);
        for (int t = 0; ; ++t)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == 0)
            {
                break;
            }
            temp[t] = expression[i];
            ++i;
            printf("d %d\n",i);
        }
        strcpy(num2, temp);
        if (status == '+')
        {
            pl();
        }
        if (status == '-')
        {
            minus();
        }
    }
    for (int t= 0; rlt[t] != 0; ++t)
    {
        printf("%c\n", rlt[t]);
    }

}




















