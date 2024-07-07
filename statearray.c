#include <stdio.h>
#include <string.h>

#define STATE_ARRAY_SIZE 256 // Adjust the size as needed

void printBits(unsigned char byte)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (byte >> i) & 1);
    }
}

void textToStateArray(const char *text, unsigned char stateArray[], size_t *stateSize)
{
    size_t len = strlen(text);
    *stateSize = len;

    for (size_t i = 0; i < len; i++)
    {
        stateArray[i] = text[i];
    }
}

int main()
{
    char plainText[STATE_ARRAY_SIZE];
    unsigned char stateArray[STATE_ARRAY_SIZE];
    size_t stateSize;

    // Input plain text
    printf("Enter plain text: ");
    fgets(plainText, STATE_ARRAY_SIZE, stdin);

    // Remove newline character from fgets
    size_t len = strlen(plainText);
    if (len > 0 && plainText[len - 1] == '\n')
    {
        plainText[len - 1] = '\0';
    }

    // Convert plain text to state array
    textToStateArray(plainText, stateArray, &stateSize);

    // Print the state array in bits
    printf("State array in bits:\n");
    for (size_t i = 0; i < stateSize; i++)
    {
        printBits(stateArray[i]);
        printf(" ");
    }
    printf("\n");

    // Print the state array in hex
    printf("Hexadecimal State Array:\n");
    for (size_t i = 0; i < stateSize; i++)
    {
        printf("%02X ", stateArray[i]);
    }

    printf("\n");

    return 0;
}
