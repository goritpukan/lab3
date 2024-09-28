#include <stdio.h>
#include "../include/validation.h"

void handleInput(const double *coefficientVariable, const char coefficientChar) {
    char isValid = 0;
    do {
        printf("Please enter a coefficient (from -1e100 to 1e100) %c: ", coefficientChar);
        isValid = scanf("%lf", &*coefficientVariable);
        while(getchar() != '\n');
        if (!isValid) {
            printf("Error, try again.\n");
        }
        if(*coefficientVariable < -1e100 || *coefficientVariable > 1e100) {
            printf("You can enter coefficient in ONLY range(-1e100 - 1e100)\n");
            printf("Please, try again\n");
            isValid = 0;
        }
    } while (!isValid);
}
