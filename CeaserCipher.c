/*Write a program in C to encrypt and decrypt the user input message and key using Ceaser Cipher*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ceaser Cipher\n");
    char input[100], ch;
    int key, i;
printf("Encryption and decryption of input message using caesar cipher:\n");

    printf("Enter the message to encrypt and decrypt:");
    gets(input);

    printf("Enter the key(key should be of range 0-25):");
    scanf("%d", &key);

    // Encryption of input message
    for(i = 0; input[i] != '\0'; ++i){
        ch = input[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            input[i] = ch;
        }
    }
    printf("Encrypted message of input message: %s\n", input);

    // Decryption for encrypted message
    for(i = 0; input[i] != '\0'; ++i){
        ch = input[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            input[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            input[i] = ch;
        }
    }
    printf("Decrypted message is: %s\n", input);

    return 0;
}

