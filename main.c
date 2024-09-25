#include <stdio.h>
#include "include/validation.h"
#include "include/calculations.h"

int main(void) {
    double a = 0, b = 0, c = 0;
    char restart = 0;
    XResults xResults = {};

    printf("This is program, that calculates cubic equality x^3 + a * x^2 + b * x + c = 0\n");
    do {
        handleInput(&a, 'A');
        handleInput(&b, 'B');
        handleInput(&c, 'C');

        xResults = calcX(a, b, c);

        if (xResults.error) {
            printf("Error!");
            //handle it
        } else {
            printf("x1 = \%lf\nx2 = \%lf\nx3 = \%lf\n", xResults.x1, xResults.x2, xResults.x3);
        }
        printf("Print \"r\" for restart: ");
        restart = getchar();
    } while (restart == 'r');
    return 0;
}
