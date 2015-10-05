#include <stdio.h>
#include <string.h>
#include <assert.h>
void swap(char str1[], char str2[])
{
    assert(str1 != str2);  /* （假装）我觉得这里绝对不会出现两个相同的字符串 */
    char temp[500];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
void quicksort(char name[][500], int left, int right)
{
    int i = left;
    int j = right;
    char base[500];
    strcpy(base, name[left]);
    if (left < right)
    {
        for(;i < j;)
        {
            for (; i < j && (strcmp(name[j], base) >= 0);--j){}
            for (; i < j && (strcmp(name[i], base) <= 0);++i){}
            if (i != j){swap(name[i], name[j]);}
        }
    }
    if (left != i)
    {
        swap(name[left], name[i]);        
    }
    quicksort(name, left, i);
    quicksort(name, i + 1, right);
}


int main()
{
    int i = 0;
    int num[10000];
    char name[10000][500];
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
    quicksort(name, 0, total - 1);


    for (int t = 0; t < total; ++t)
    {
        printf("%s %d\n", name[t],num[t]);
    }


}



















