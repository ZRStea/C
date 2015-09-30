#include <stdio.h>
#include <string.h>

int main()

{   
    int N,N1;
    char result[50000];
    scanf("%d", &N);
    N1 = N;
    int i = 0;
    for (; N>0; --N)
    {
        char num[10000];
        scanf("%s", num);
        int length;
        length = strlen(num);
        if ((num[length - 1] - 48) % 2 == 0)
        {
            result[i] = 'e';
            result[i+1] = 'v';
            result[i+2] = 'e';
            result[i+3] = 'n';
            result[i+4] = '\n';
            i = i+5;
        }
        else 
        {   
            result[i] = 'o';
            result[i+1] = 'd';
            result[i+2] = 'd';
            result[i+3] = '\n';
            i = i+4;
        }
        
    }

    // for (int i = 0; i <= N1; ++i)
    // {
        printf("%s", result);
        // printf("%c", result[i][1]);
        // printf("%c", result[i][2]);
        // printf("%c", result[i][3]);
    // }

}