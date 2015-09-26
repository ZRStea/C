#include <stdio.h>
#include <string.h>
char num1[2000];
char num2[2000];
char plus[2000];
int length1;
int length2;
int pl()
{
    if (length1>=length2)
    {    }
    else
    {
        int temp;
        temp = length2;
        length2 = length1;
        length1 = temp;
    }
    int temp,n = 0;
    for (; length1>=0; )
    {
        if (length2 >= 0)
        {
            temp = (num1[length1] + num2[length2] + n) - 192;
            if (temp < 10)
            {
                plus[length1] = (char) (temp + 64);
                n = 0;
            }
            else
            {
                n = 1;
                plus[length1] = (char) (temp + 54);
            }
        --length2;
        --length1;
        }
        else
        {
            temp = (num1[length1] + '0' + n) - 192;
            if (temp < 10)
            {
                plus[length1] = (char) (temp + 64);
                n = 0;
            }
            else
            {
                n = 1;
                plus[length1] = (char) (temp + 54);
            }
        --length1;
        }
    }
    return 0;
}

int main()
{
    length2 = 4;
    length1 = 5;
    strcpy(num1,"12010");
    strcpy(num2,"1203");
    pl();
    printf("%s\n",plus);
    puts(plus);
    puts(num1);
    puts(num2);
    puts(length2);
    puts(length1);
    return 0;
}