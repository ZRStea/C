#include <stdio.h>
#include <string.h>

void quicksort(int num[], int left, int right)//这个算法忘记考虑怎么在任何情况下都把基准放到正确位置 修补成本太高 废弃
{
    int temp[right - left + 1];
    int base = num[left];
    int j = 0;
    int k = right - left;
    if (left < right)
    {
        for (int i = left; i <= right; ++i)
        {
            if (num[i] < base)
            {
                temp[j] = num[i];
                ++j;
            } 
            if (num[i] > base)
            {
                temp[k] = num[i];
                --k;
            }
            printf("j=%d k=%d\n",j,k);
            temp[j] = base;
            }
        int t = 0;
        for (int i = 0; i <= (right - left); ++i)
        {
            num[left + t] = temp[i];
            ++t;
        }
    quicksort(num, left, left+j-1);
    quicksort(num, left+j+1, right);
    }
}
int main()
{
    int num[10] = {5,6,2,9,100,110,1,1,2,3,4,5};
    quicksort(num, 0, 9);

    for (int i = 0;i<=9;++i){
        printf("%d\n", num[i]);
    }
    return 0;
}
