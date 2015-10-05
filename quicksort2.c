#include <stdio.h>
// void swap(int *a, int *b)//交换函数
// {
//     int t;
//     t = *a;
//     *a = *b;
//     *b = t;
// }
void quicksort(int num[], int left, int right)//left right均为num[]中坐标 标记函数作用范围
{
    int i = left;
    int j = right;
    int base = num[left];//保存base元素 挖第一个坑
    if (left < right)//控制递归结束
    {
    for (; i < j; )
    {
        for(; i < j && num[j] >= base; --j){}//从后向前搜索小于base的元素
        num[i] = num[j];//找到后填进左边的坑 j成为新坑
        for(; i < j && num[i] <= base; ++i){}//从前向后搜索大于base的元素
        num[j] = num[i];//填给右边j坑 i坑成为新坑 之后循环
    }
    num[i] = base;//填入最后一个坑
    quicksort(num, left, i - 1);//分治递归
    quicksort(num, i + 1, right);       
    }
}

int main()
{
    int num[13] = {5,6,2,3,7,4,1,435,6,0,6,0,0};
    quicksort(num, 0, 12);

    for (int i = 0;i<=12;++i){
        printf("%d\n", num[i]);
    }
    return 0;
}
