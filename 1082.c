#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    int num[1000];
    char name[1000][1000];
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
    char temp[1000];//冒泡排序name
    for (int i = 0; ; ++i)
    {
        int times = 0;
        for (int t = 0; name[i][t] != '\0' && name[i+1][t] != '\0'; ++t)
        {
            if (name[i][t] > name[i+1][t])
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[i+1]);
                strcpy(name[i+1], temp);
                ++times;
                break;
            }
        }
        if (times == 0)
        {
            break;
        }
    }
    for (int t = 0; t < total; ++t)
    {
        printf("%s %d", name[t],num[t]);
    }


}





















