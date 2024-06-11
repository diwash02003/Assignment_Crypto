#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int n) {
    int t, t1 = 0, t2 = 1;
    int r = n, r1 = a, r2;

    while (r1 != 0) {
        int q = r / r1;
        t = t2 - q * t1;
        t2 = t1;
        t1 = t;

        r2 = r % r1;
        r = r1;
        r1 = r2;
    }

    if (r > 1)
        return -1; // Modular inverse does not exist
    if (t2 < 0)
        t2 += n;

    return t2;
}

int main() {
    int a, n;
    printf("Enter the integer (a): ");
    scanf("%d", &a);
    printf("Enter the modulo (n): ");
    scanf("%d", &n);

    int gcd_val = gcd(a, n);
    if (gcd_val != 1) {
        printf("Modular inverse does not exist for %d mod %d\n", a, n);
    } else {
        int inverse = mod_inverse(a, n);
        printf("Modular inverse of %d mod %d is: %d\n", a, n, inverse);
    }

    return 0;
}
