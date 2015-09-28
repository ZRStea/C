#include <stdio.h>
#include <string.h>

#define LENGTH 10000

int a[LENGTH]={0};
int b[LENGTH]={0};
int s[LENGTH]={0};

void strrev(char * ptr) {
    size_t len=strlen(ptr);
    char * pL=ptr;
    char * pR=ptr+len-1;
    while (pL < pR) {
        *pL ^= *pR ^= *pL ^= *pR;
        pL++, pR--;
    }
}

int main() {
    char str[LENGTH];
    /* reading num A from keyboard */
    scanf("%s", str);
    strrev(str);
    for (int i=0; str[i]!='\0'; ++i) {
        a[i] = str[i] - '0';
    }
    /* reading num B from keyboard */
    scanf("%s", str);
    strrev(str);
    for (int i=0; str[i]!='\0'; ++i) {
        b[i] = str[i] - '0';
    }
    /* plus */
    for (int i=0; i<LENGTH-1; ++i) {
        s[i] += a[i] + b[i];
        s[i+1] = s[i] / 10;
        s[i] %= 10;
    }
    /* print s */
    int *p=s+LENGTH-1;
    while (*p == 0) {
        p--;
    }
    while (p >= s) {
        putchar(*p + '0');
        p--;
    }
    return 0;
}
