#include <stdio.h>
#include <string.h>
void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void quicksort(int num[], int l, int h)
{
    printf("l=%d h=%d\n", l, h);
    int i = l + 1;
    int j = h;
    int t = l;
    if (l < h)
    {
        int temp;
        temp = num[l];
        /*  3 1 4 2 5
         *  1 2 4 3 5
         *  l   0
         *  h   4
         *  i   3
         *  j   4
         *  t   1
         */
        for (; i <= h; ++i)
        {
            if (num[i] < temp)
            {
                swap(&num[t], &num[i]);
                t = i;
            }
        }
        for (j = t; j >= l ; --j)
        {
            if (num[j] > temp)
            {
                swap(&num[t], &num[j]);
                t = j;
            }
        }
        quicksort(num, l, t - 1);
        quicksort(num, t + 1, h);
    }
    /* 1 下面这两行当 l < h 不成立的时候也会执行 */
    /* 2 变量 j 而不是变量 t ? */
}

int main()
{
    int num[7] = {5,6,2,3,7,4,1};
    quicksort(num, 0, 6);

    for (int i = 0;i<=6;++i){
        printf("%d", num[i]);
    }
    return 0;
}
