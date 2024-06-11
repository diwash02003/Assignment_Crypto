#include <stdio.h>
#include <math.h>
int power_mod(int x, unsigned int y, int p)
{
    int result = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % p;
        // y must be even now
        y = y >> 1;      // y = y/2
        x = (x * x) % p; // Change x to x^2
    }
    return result;
}
int main()
{
    int p, a;

    // Taking input
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    printf("Enter a number (a) such that 1 < a < %d: ", p - 1);
    scanf("%d", &a);
    // Fermat's Little Theorem test
    if (a <= 1 || a >= p - 1)
    {
        printf("Invalid input: 1 < a < %d\n", p - 1);
        return 1;
    }
    int result = power_mod(a, p - 1, p);
    if (result == 1)
    {
        printf("The input number is prime....\n");
        printf("Fermat's Little Theorem holds: %d^(%d-1) ≡ 1 (mod %d)\n", a, p, p);
    }
    else
    {
        printf("Fermat's Little Theorem does not hold: %d^(%d-1) ≡ %d (mod %d)\n", a, p, result, p);
        printf("The input number is not prime....");
    }
    return 0;
}