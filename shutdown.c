#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Perform a simple addition operation
    int a = 1;
    int b = 2;
    int sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("The system will shut down in %d minutes...\n", sum);

    char command[50];
    snprintf(command, sizeof(command), "shutdown -P +%d", sum);

    // Schedule the shutdown
    system(command);

    return 0;
}
