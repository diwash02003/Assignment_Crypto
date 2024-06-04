// write a program to test if the number is primitive root or not
#include <stdio.h>
#include <stdbool.h>

bool is_primitive_root(int g, int p) {
    // Calculate g^i mod p for i = 1 to p-1
    int values[p - 1];
    for (int i = 1; i < p; i++) {
        values[i - 1] = 1;
        for (int j = 0; j < i; j++) {
            values[i - 1] = (values[i - 1] * g) % p;
        }
    }
    // Printing array
    printf("Array values: ");
    for (int i = 0; i < p - 1; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    // check for distinct values
    for (int i = 0; i < p - 2; i++) {
        for (int j = i + 1; j < p - 1; j++) {
            if (values[i] == values[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int p, g;
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the value of g: ");
    scanf("%d", &g);

    if (is_primitive_root(g, p)) {
        printf("%d is a primitive root modulo %d\n", g, p);
    } else {
        printf("%d is not a primitive root modulo %d\n", g, p);
    }
    return 0;
}
