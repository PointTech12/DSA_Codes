/* Joshua Bara
    IT - 03 */
/*Write a C program to generate Pascal Triangle using array.*/

#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int numrow;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numrow);

    for (int i = 0; i < numrow; i++) {
        for (int space = 0; space < numrow - i; space++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            int coefficient = factorial(i) / (factorial(j) * factorial(i - j));
            printf("%d ", coefficient);
        }
        printf("\n");
    }

    return 0;
}

