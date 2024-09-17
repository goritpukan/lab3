#include <stdio.h>
#include "../include/handleInput.h"


void handleInput(double *coefficientVariable, char coefficientChar) {
    char isValid = 0;
    do {
        printf("Please enter a coefficient \%c: ", coefficientChar);
        isValid = scanf("%lf", &coefficientVariable);
        fflush(stdin);
        if (!isValid) {
            printf("Error, try again.\n");
        }
    } while (!isValid);
}
