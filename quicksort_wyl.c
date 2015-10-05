#include <stdio.h>

#define SWAP(a, b) {int t=a; a=b; b=t;}  /* swap two variables */

void quicksort(int d[], int L, int R) {
    int l=L, r=R-1, pivot=L;
    if (L < R) {
        while (l != r) {
            while (d[pivot] <  d[r] && l != r) r--;
            while (d[pivot] >= d[l] && l != r) l++;
            SWAP(d[l], d[r]);
        }
        SWAP(d[pivot], d[l]);
        quicksort(d, L, l);  /* l == r here */
        quicksort(d, l+1, R);
    }
    return;
}

int N;
int num[1000000];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", num+i);
    }

    quicksort(num, 0, N);

    for (int i=0; i<N; ++i) {
        printf("%d ", num[i]);
    }

    return 0;
}

