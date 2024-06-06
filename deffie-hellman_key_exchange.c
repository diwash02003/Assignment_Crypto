#include <stdio.h>
#include <math.h>

int main()
{

    int p, g, yB, yA, privateKeyALice, privateKeyBob, secretkeyAlice, secretkeyBob;
    printf("Enter p and g:");
    scanf("%d%d", &p, &g);
    printf("----------------------------------------------\n\n");
    printf("Enter private key for Alice:");
    scanf("%d", &privateKeyALice);
    printf("----------------------------------------------\n\n");
    yA = (int)pow(g, privateKeyALice) % p;
    printf("Enter private key for Bob:");
    scanf("%d", &privateKeyBob);
    printf("----------------------------------------------\n\n");
    yB = (int)pow(g, privateKeyBob) % p;

    secretkeyAlice = (int)pow(yB, privateKeyALice) % p; // Secret key for Alice
    secretkeyBob = (int)pow(yA, privateKeyBob) % p;     // Secret key for Bob

    if (secretkeyAlice == secretkeyBob)
    {
        printf("since both keys are same , key exchanged successfully.\n");
        printf("----------------------------------------------\n\n");
        printf("Secret key for the Alice is : %d\n", secretkeyAlice);
        printf("Secret Key for the Bob is : %d\n", secretkeyBob);
        printf("----------------------------------------------\n\n");
    }
    else
    {
        printf("key exchanged failed.");
        printf("----------------------------------------------\n\n");
    }
    return 0;
}