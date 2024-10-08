#include <stdio.h>
#include "../include/validation.h"

void handleInput(const double *coefficientVariable, const char coefficientChar) {
    char isValid = 0;
    do {
        printf("Please enter a coefficient (from -1e6 to 1e6) %c: ", coefficientChar);
        isValid = scanf("%lf", &*coefficientVariable);
        while(getchar() != '\n');
        if (!isValid) {
            printf("Error, try again.\n");
        }
        if(*coefficientVariable < -1e6 || *coefficientVariable > 1e6) {
            printf("You can enter coefficient ONLY in range(-1e6 - 1e6)\n");
            printf("Please, try again\n");
            isValid = 0;
        }
    } while (!isValid);
}
//різниця 12 порядків валідація