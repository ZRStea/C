#include <stdio.h>
#include <string.h>

void quicksort(int num[], int left, int right)
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
    int num[12] = {5,6,2,9,100,110,1,3,0,0,8,10};
    quicksort(num, 0, 11);

    for (int i = 0;i<=11;++i){
        printf("%d\n", num[i]);
    }
    return 0;
}
