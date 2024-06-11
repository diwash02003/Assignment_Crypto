#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

void toUpperCase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        str[i] = toupper(str[i]);
    }
}

void generateKey(char *str, char *key, char *keyGenerated)
{
    int strLen = strlen(str);
    int keyLen = strlen(key);
    for (int i = 0, j = 0; i < strLen; ++i, ++j)
    {
        if (j == keyLen)
            j = 0;
        keyGenerated[i] = key[j];
    }
    keyGenerated[strLen] = '\0';
}

void encrypt(char *str, char *key, char *encrypted)
{
    int strLen = strlen(str);
    for (int i = 0; i < strLen; ++i)
    {
        encrypted[i] = ((str[i] + key[i]) % 26) + 'A';
    }
    encrypted[strLen] = '\0';
}

void decrypt(char *encrypted, char *key, char *decrypted)
{
    int strLen = strlen(encrypted);
    for (int i = 0; i < strLen; ++i)
    {
        decrypted[i] = (((encrypted[i] - key[i]) + 26) % 26) + 'A';
    }
    decrypted[strLen] = '\0';
}

int main()
{
    char str[MAX_LENGTH], key[MAX_LENGTH], keyGenerated[MAX_LENGTH], encrypted[MAX_LENGTH], decrypted[MAX_LENGTH];
    printf("Enter the plaintext: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove trailing newline

    // Convert both plaintext and key to uppercase
    toUpperCase(str);
    toUpperCase(key);

    // Generate the repeated key
    generateKey(str, key, keyGenerated);

    // Encrypt the plaintext
    encrypt(str, keyGenerated, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    // Decrypt the ciphertext
    decrypt(encrypted, keyGenerated, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
