#include <stdio.h>
#include "../include/validation.h"

void handleInput(double *coefficientVariable, char coefficientChar) {
    char isValid = 0;
    do {
        printf("Please enter a coefficient (from -10000 to 10000) \%c: ", coefficientChar);
        isValid = scanf("%lf", &*coefficientVariable);
        fflush(stdin);
        if (!isValid) {
            printf("Error, try again.\n");
        }
        if(*coefficientVariable < -10000 || *coefficientVariable > 10000) {
            printf("You can enter coefficient in ONLY range(-10000 - 10000)\n");
            printf("Please, try again\n");
            isValid = 0;
        }
    } while (!isValid);
}
