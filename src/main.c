#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

void generateHexKey(char *key, int length) {
    const char hexDigits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Generate each character of the hex key
    for (int i = 0; i < length; ++i) {
        key[i] = hexDigits[rand() % 36];  // Choose a random hexDigit
    }

    // Null-terminate the string
    key[length] = '\0';
}

int main() {
    // Seed the random number generator
    int entropy_source1 = 32;
    int entropy_source2 = 64;
    int entropy_source3 = 128;
    unsigned int seed = (unsigned int)time(NULL)
    ^ (unsigned int)getpid()
    ^ (unsigned int)(uintptr_t)&entropy_source1
    ^ (unsigned int)(uintptr_t)&entropy_source2
    ^ (unsigned int)(uintptr_t)&entropy_source3;
    srand(seed);

    int keys;   // How many Hex Keys to generate
    int keyLength;  // Desired length of each Hex Key

    printf("\nHow many keys should be generated?\n> ");
    scanf("%i", &keys);
    printf("How long should the keys be?\n> ");
    scanf("%i", &keyLength);

    char hexKey[keyLength + 1];  // +1 for the null terminator

    for (int i = 0; i < keys; i++)
    {
        generateHexKey(hexKey, keyLength);

        printf("Generated Hex Key #%i:\n%s\n\n", i + 1, hexKey);
    }

    return 0;
}
