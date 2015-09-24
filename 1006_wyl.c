#include <stdio.h>

#define to_digit(x) ((x) - '0')

int main() {
    char isbn[100];  // e.g. 0-670-82162-4
    gets(isbn); 
    int checksum = (
        to_digit(isbn[0])  * 1 +
        to_digit(isbn[2])  * 2 +
        to_digit(isbn[3])  * 3 +
        to_digit(isbn[4])  * 4 +
        to_digit(isbn[6])  * 5 +
        to_digit(isbn[7])  * 6 +
        to_digit(isbn[8])  * 7 +
        to_digit(isbn[9])  * 8 +
        to_digit(isbn[10]) * 9 ) % 11;
    char checksum_char = checksum == 10 ? 'X' : (char)(checksum + '0');
    if (isbn[12] == checksum_char) {
        puts("Right\n");
    } else {
        isbn[12] = checksum_char;
        puts(isbn);
    }
    return 0;
}

