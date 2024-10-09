#include <stdio.h>
#include "include/inputOutput.h"
#include "include/calculations.h"

int main(void) {
    double a = 0, b = 0, c = 0;
    char outputType = 0;
    unsigned char outputAccuracy = 0;

    XResults xResults = {};

    printf("This is program, that calculates cubic equality x^3 + a * x^2 + b * x + c = 0\n");
    do {
        handleCoeffInput(&a, 'A');
        handleCoeffInput(&b, 'B');
        handleCoeffInput(&c, 'C');
        xResults = calcX(a, b, c);

        if (xResults.error) {
            printf("Error!\n");
        } else {
            handleOutputType(&outputType, &outputAccuracy);
            outputResult(xResults, outputType, outputAccuracy);
        }
        printf("Print \"r\" for restart: ");
    } while (getchar() == 'r');
    return 0;
}
