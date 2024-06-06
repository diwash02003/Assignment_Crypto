#include <stdio.h>

// Function to check if two numbers are coprime (relatively prime)
int are_coprime(int a, int b) {
    for (int i = 2; i <= a && i <= b; ++i) {
        if (a % i == 0 && b % i == 0) {
            return 0; // Not coprime
        }
    }
    return 1; // Coprime
}
// Function to calculate Euler's Totient Function (Phi function)
int euler_totient(int n) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        if (are_coprime(i, n)) {
            ++result;
        }
    }
    return result;
}
int main(){
    // write a program to calculate the euler totient function of input integer
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    int phi = euler_totient(n);

    printf("Euler's Totient Function (Phi function) of %d is: %d\n", n, phi);

    return 0;
}
