#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

void generate_hex_key(char *key, int length) {
    const char hex_digits[] = "0123456789ABCDEF";

    // Generate each character of the hex key
    for (int i = 0; i < length; ++i) {
        key[i] = hex_digits[rand() % 16];  // Choose a random hex digit
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

    int keys;   // How many Hexes to generate
    int key_length;  // Desired length of the hex key

    printf("\nHow many keys should be generated?\n> ");
    scanf("%i", &keys);
    printf("How long should the keys be?\n> ");
    scanf("%i", &key_length);

    char hex_key[key_length + 1];  // +1 for the null terminator

    for (int i = 0; i < keys; i++)
    {
        generate_hex_key(hex_key, key_length);

        printf("Generated Hex Key #%i:\n%s\n\n", i + 1, hex_key);
    }

    return 0;
}
