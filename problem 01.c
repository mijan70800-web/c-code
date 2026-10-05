#include <stdio.h>

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    switch ((number > 0) - (number < 0)) {
        case 1:
            printf("The number is positive.");
            break;
        case -1:
            printf("The number is negative.");
            break;
        case 0:
            printf("The number is zero.");
            break;
    }

    return 0;
}
