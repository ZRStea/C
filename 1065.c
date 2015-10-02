#include <stdio.h>
int main()
{
    int month[12];
    int acc = 0;
    int mom = 0;
    int t = 0;
    int i = 0;
    // FILE *fp;
    // FILE *wt;
    // fp = fopen("save.in", "r");
    // wt = fopen("save.out", "w+");
    scanf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", &month[0], &month[1], &month[2], &month[3], &month[4], &month[5], &month[6], &month[7], &month[8], &month[9], &month[10], &month[11]);
    // for(int i = 0; i<=11; ++i)
    // {
    //     printf("%d\n", month[i]);
    // }
    // fclose(fp);
    for (; i<=11; ++i)
    {
        acc += 300;
        if (acc - month[i] >= 100)
        {
            t = (acc - month[i]) / 100;
            // printf("t=%d\n", t);
            acc -= (100 * t);
            mom += (100 * t);
            // printf("%d\n", mom);
            acc -= month[i];
        }
        else
        {
            if (acc - month[i] < 0)
            {
                // fprintf(wt, "-%d", (i+1));
                printf("-%d\n", (i+1));
                break;
            }
            acc -= month[i];
        }
    }
    if (i == 12)
    {
        // fprintf(wt, "%d\n", (mom*120/100+acc));
        printf("%d\n", (mom*120/100+acc));
    }
    // fclose(wt);
    return 0;
}
