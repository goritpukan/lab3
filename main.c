#include <stdio.h>
#include "include/validation.h"
#include "include/calculations.h"

int main(void) {
    double a = 0, b = 0, c = 0;
    char restart = 0;
    XResults xResults = {};
    char complex[3];

    printf("This is program, that calculates cubic equality x^3 + a * x^2 + b * x + c = 0\n");
    do {
        handleInput(&a, 'A');
        handleInput(&b, 'B');
        handleInput(&c, 'C');

        xResults = calcX(a, b, c);

        if (xResults.isComplex) {
            complex[0] = '*';
            complex[1] = 'i';
        } else {
            complex[0] = '\0';
        }

        if (xResults.error) {
            printf("Error!\n");
        } else {
            printf("x1 = %g\nx2 = %g%s\nx3 = %g%s\n", xResults.x1, xResults.x2, complex ,xResults.x3, complex);
        }
        printf("Print \"r\" for restart: ");
        restart = getchar();
        while(getchar() != '\n');
    } while (restart == 'r');
    return 0;
}
