#include <stdio.h>

int main() {
    int sum=0;
    char num[160];
    int isbn[100];
    scanf("%s", num);
    int t=0;
    
    for (int i=0; i<=13; ++i) {
        if (num[i] == '-') {
        }
        else {
            isbn[t] = (int)num[i] - 48;
            t = t+1;
        }
    }


    for (int i=0; i<=8; ++i){
        sum = sum + isbn[i]*(i+1);
        // printf("%d",isbn[i]);
    }
    sum = sum % 11;
    if (isbn[9] == sum || (sum == 10 && isbn[9] == 56)) {
        printf("Right\n");
    }
    else {
        
        if (sum == 10) {
            num[12] = 'X';
        }
        else {
            num[12] = (char)(sum+48);
        }
        puts(num);
    }

    return 0;
}

