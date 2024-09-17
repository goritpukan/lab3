#include <stdio.h>
#include "include/handleInput.h"

int main(void) {
    double a = 0, b = 0, c = 0;
    char restart = 'r';
    printf("This is program, *program description*\n");
    do {
        handleInput(&a, 'A');
        handleInput(&b, 'B');
        handleInput(&c, 'C');
        printf("Print \"r\" for restart: ");
        fflush(stdin);
        scanf("%c", &restart);
    } while (restart == 'r');
    return 0;
}
