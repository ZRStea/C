#include <stdio.h>
#include <string.h>
void sawp(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void quicksort(int num[], int l, int h)
{
    int i = l + 1;
    int j = h;
    int t = l;
    if (l < h)
    {
        int temp;
        temp = num[l];
        for (; i <= h; ++i)
        {
            if (num[i] < temp)
            {
                sawp(&num[t], &num[i]);
                t = i;
            }
        }
        for (; j >= l ; --j)
        {
            if (num[j] > temp)
            {
                sawp(&num[t], &num[j]);
                t = j;
            }
        }
    }
    quicksort(num, l, j - 1);
    quicksort(num, j + 1, h);
}

int main()
{
    int num[10] = {2,3,4,5,6,7,8,9,1,0};
    quicksort(num, 0, 9);

for (int i = 0;i<=9;++i){
    printf("%d", num[i]);
}
}