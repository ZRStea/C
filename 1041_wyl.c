#include <stdio.h>
#include <ctype.h>
/* without big number support */
int main() {
    int acc=0;  /* accumulator */
    int last_operand=0;
    char last_operator='+';
    char expression[256];
    gets(expression);  /* notice function gets is insecure in practical production */
    for (char *p=expression; ; ++p) {
        if (isdigit(*p)) {
            last_operand = last_operand*10 + (*p - '0');
        } else {
            if (last_operator == '+') {
                acc += last_operand;
            } else {
                acc -= last_operand;
            }
            last_operator = *p;
            last_operand = 0;
            if (last_operator == '\0') {
                break;
            }
        }
    }
    printf("%d", acc);
    return 0;
}

