#include <stdio.h>
#include <string.h>
void sawp(char str1[], char str2[])
{
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
void quicksort(char num[][100], int l, int h)
{
    int i = l + 1;
    int j = h;
    int t = l;
    if (l < h)
    {
        char temp[100];
        strcpy(temp, num[l]);
        for (; i <= h; ++i)
        {
            if (strcmp(num[i], temp) < 0)
            {
                sawp(num[t], num[i]);
                t = i;
            }
        }
        for (; j >= l ; --j)
        {
            if (strcmp(num[j], temp) > 0)
            {
                sawp(num[t], num[j]);
                t = j;
            }
        }
    }
    quicksort(num, l, j - 1);
    quicksort(num, j + 1, h);
}


int main()
{
    int i = 0;
    int num[10000];
    char name[10000][100];
    int total = 0;
    scanf("%d\n", &total);
    for (; i < total; ++i)
    {
        scanf("%s\n", name[i]);    
    }
    for (int t = 0; i < total*2; ++i)
    {
        scanf("%d", &num[t]);
        ++t;
    }
    //测试输入语句
    // for (int t = 0; t < total; ++t)
    // {
    //     printf("%s\n", name[t]);
    // }
    // for (int t = 0; t < total; ++t)
    // {
    //     printf("%d\n", num[t]);
    // }
    for (; ; ) //冒泡排序数字
    {  
        int times = 0; 
        for (int t = 0; t < total - 1; ++t)
        {
            if (num[t] > num[t+1])
            {
                num[t] ^= num[t+1] ^= num[t] ^= num[t+1];
                ++times;
            }
        }
        if (times == 0)
        {
            break;
        }
    }
    //测试排序语句
    // for (int t = 0; t < total; ++t)
    // {
    //     printf("%s\n", name[t]);
    // }
    // char temp[1000];//冒泡排序name
    // for (; ; )
    // {
    //     int times = 0;
    //     for (int i = 0; i < total -1; ++i)
    //     {
    //         if (strcmp(name[i],name[i+1]) > 0)
    //         {
    //             strcpy(temp, name[i]);
    //             strcpy(name[i], name[i+1]);
    //             strcpy(name[i+1], temp);
    //             ++times;
    //         }
    //     }
    //     if (times == 0)
    //     {
    //         break;
    //     }
    // }
    quicksort(name, 0, total);


    for (int t = 0; t < total; ++t)
    {
        printf("%s %d\n", name[t],num[t]);
    }


}



















