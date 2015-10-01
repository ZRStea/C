#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
char rlt[2000];
char temp[2000];
char expression[2000];
char status;
int delte(char num[2000])
{
    for (int i = 0; i <= strlen(num); ++i)
    {
        num[i] = 0;
    }
    return 0;
}
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
    int i= 0;
    for (int t = 0; ; ++i)
    {
        // printf("t=%d\ti=%d\n", t, i);
        if (expression[i] == '+' || expression[i] == '-')
        {
            status = expression[i];
            break;
        }
        num1[t] = expression[i];
        ++t;
    }
    ++i;
    for (int t = 0; ; ++i)
    {
        if (expression[i] == '+' || expression[i] == '-')
        {
            break;
        }
        num2[t] = expression[i];
        ++t;
    }
    if (status == '+')
    {
        pl();
    }
    if (status == '-')
    {
        minus();
    }
    status = expression[i];
    ++i;
    for (; ; )
    {
        delte(num1);
        strcpy(num1, rlt);
        delte(rlt);
        delte(num2);
        for (int t = 0; i < strlen(expression); ++i) 
        {
            if (expression[i] == '+' || expression[i] == '-')
            {
                if (status == '+')
                {
                    pl();
                }
                if (status == '-')
                {
                    minus();
                }
                status = expression[i];
                break;
            }
            num2[t] = expression[i];
        }
        if (i >= strlen(expression))
        {
            break;
        }

    }
    printf("%s\n", rlt);
    return 0;

}












