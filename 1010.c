#include <stdio.h>

int prime(int num){
    if (num==0||num==1)
    {
       return 0;
    }
    else{
        for (int i = num - 1;i>=2;--i){
            if (num%i == 0){
                return 0;
            }
        }
    return 1;
    }
}

int maxn(char str[200]){
    int maxnum= 0;
    for (char n = 'a';(int)n<=122;++n){
        int tempnum=0;
        for (int i = 0;str[i]!='\0';++i){
            if (str[i]==n){
                ++tempnum;
            }
        }
        if (tempnum>maxnum){
            maxnum = tempnum;
        }

    }
    return maxnum;
}

int minn(char str[200]){
    int minnum= 0;
    for (char n = 'a';(int)n<=122;++n){
        int tempnum=0;
        for (int i = 0;str[i]!='\0';++i){
            if (str[i]==n){
                ++tempnum;
            }
        }
        if (minnum==0){
            minnum = tempnum;}
        if (tempnum != 0)
        {
            if (tempnum < minnum)
            {
                minnum = tempnum;
            }
        }

    }
    return minnum;
}

int main(){
    char str[200];
    scanf("%s",str);
    int mins = (maxn(str) - minn(str));
    if (prime(mins)==1)
    {
        printf("Lucky Word\n");
        printf("%d\n",mins);
    }
    else{
        printf("No Answer\n");
        printf("%d\n",0);
    }
    return 0;
}