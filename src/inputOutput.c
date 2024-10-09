#include <stdio.h>
#include "../include/inputOutput.h"
#include "../include/calculations.h"

void handleCoeffInput(const double *coefficientPointer, const char coefficientChar) {
    char isValid = 0;
    do {
        printf("Please enter a coefficient (from -1e80 to 1e80) %c: ", coefficientChar);
        isValid = scanf("%lf", &*coefficientPointer);
        while (getchar() != '\n');
        if (!isValid) {
            printf("Error, try again.\n");
        }
        if (*coefficientPointer < -1e80 || *coefficientPointer > 1e80) {
            printf("You can enter coefficient ONLY in range(-1e80 - 1e80)\n");
            printf("Please, try again\n");
            isValid = 0;
        }
    } while (!isValid);
}

void handleOutputType(const char *outputTypePointer, const unsigned char *outputAccuracyPointer) {
    char isValid = 0;
    do {
        printf("\nChoose output format float / exponential(f/e):");
        isValid = scanf("%c", &*outputTypePointer);
        while (getchar() != '\n');
        if (!isValid) {
            printf("\nError, try again.");
        }
        if (*outputTypePointer != 'e' && *outputTypePointer != 'f') {
            printf("Error, try again.");
            isValid = 0;
        }
        if (*outputTypePointer == 'f') {
            handleOutputAccuracy(&*outputAccuracyPointer);
        }
    } while (!isValid);
}

void handleOutputAccuracy(const unsigned char *outputAccuracyPointer) {
    char isValid = 0;
    do {
        printf("\nChoose output accuracy [1 - 15]: ");
        isValid = scanf("%hhu", &*outputAccuracyPointer);
        while (getchar() != '\n');
        if (!isValid) {
            printf("\nError, try again.");
        }
        if (*outputAccuracyPointer < 1 || *outputAccuracyPointer > 15) {
            isValid = 0;
            printf("\nChoose output accuracy Only in range [1 - 15]");
        }
    } while (!isValid);
}

void outputResult(XResults xResults, char outputType, unsigned char outputAccuracy) {
    if (outputType == 'e') {
        if (xResults.isComplex) {
            printf("x1 = %e\nx2 = %e+%e*i\nx3 = %e-%e*i\n",
                   xResults.x1,
                   xResults.complex1,
                   xResults.complex2,
                   xResults.complex1,
                   xResults.complex2);
        } else {
            printf("x1 = %e\nx2 = %e\nx3 = %ei\n", xResults.x1, xResults.x2, xResults.x3);
        }
    } else {
        if (xResults.isComplex) {
            printf("x1 = %.*lf\nx2 = %.*lf+%.*lf*i\nx3 = %.*lf-%.*lf*i\n",
                   outputAccuracy,
                   xResults.x1,
                   outputAccuracy,
                   xResults.complex1,
                   outputAccuracy,
                   xResults.complex2,
                   outputAccuracy,
                   xResults.complex1,
                   outputAccuracy,
                   xResults.complex2);
        } else {
            printf("x1 = %.*lf\nx2 = %.*lf\nx3 = %.*lf\n",
                   outputAccuracy,
                   xResults.x1,
                   outputAccuracy,
                   xResults.x2,
                   outputAccuracy,
                   xResults.x3);
        }
    }
}
