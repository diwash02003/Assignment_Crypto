#include <stdio.h>
#include <string.h>
#include <ctype.h>

void plaintext_to_state_array(const char *plaintext, unsigned char state[4][4])
{
    for (int i = 0; i < 16; i++)
    {
        int row = i / 4;
        int col = i % 4;
        if (i < strlen(plaintext) && isalpha(plaintext[i]))
        {
            state[row][col] = toupper(plaintext[i]) - 'A';
        }
        else
        {
            state[row][col] = 0;
        }
    }
}

void plaintext_to_bits(const char *plaintext, unsigned char bits[16][8])
{
    for (int i = 0; i < 16; i++)
    {
        unsigned char ch = (i < strlen(plaintext) && isalpha(plaintext[i])) ? toupper(plaintext[i]) - 'A' : 0;
        for (int j = 0; j < 8; j++)
        {
            bits[i][j] = (ch >> (7 - j)) & 1;
        }
    }
}

void print_state_array_hex(unsigned char state[4][4])
{
    printf("State array in hexadecimal format:\n");
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            printf("%02X ", state[row][col]);
        }
        printf("\n");
    }
}

void print_bits_matrix(unsigned char bits[16][8])
{
    printf("Plaintext in bits (4x4 matrix):\n");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d", bits[i][j]);
        }
        printf(" ");
        if ((i + 1) % 4 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    char plaintext[256];
    printf("Input the plaintext up to 16 characters: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    unsigned char state[4][4] = {0};
    unsigned char bits[16][8] = {0};

    plaintext_to_state_array(plaintext, state);
    plaintext_to_bits(plaintext, bits);

    print_bits_matrix(bits);
    print_state_array_hex(state);

    return 0;
}