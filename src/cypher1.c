#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char space[] = " ";
char cryptoSpace[1];

char input[513];
char output[513];

// Substitution cipher modifier
int c = 0;
// required for start from the beginning calculations
int mod;

bool sp;
char temp;
int cryptoSp;

void clearBuffer();
void cipherSpace(bool sp);

int main() {

    printf("\nSelect enryption offset:\n(Number between -25 and 25)\n> ");
    scanf(" %3i", &c);

    if (c < -25 || c > 25)
    {
        printf("\n\nERROR - Try Again\n\n");
        clearBuffer();
    }

    printf("\nWould you like to encrypt spaces?\n[Y/N]?\n> ");
    scanf(" %c", &temp);
    temp = tolower(temp);
    if (temp == 'y')
    {
        cipherSpace(true);
    }
    else
    {
        cipherSpace(false);
        printf("\nSpaces will be left as they are.\n");
    }

    clearBuffer();
    printf("\nInput message to be encrypted:\n> ");
    scanf(" %512[^\n]%*C", &input);

    int length = strlen(input);

    for (int u = 0; u < length; u++)
    {
        input[u] = toupper(input[u]);
    }

    printf("\nFollowing text will be encrypted, please wait...\n> %s\n", input);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (input[i] == alpha[j])
            {
                // to start from 1st letter
                int mod = j + c;
                if (j + c >= 26)
                {
                    mod = mod - 26;
                }
                else if (j + c < 0)
                {
                    mod = mod + 26;
                }
                output[i] = alpha[mod];
                mod = j + c;
            }
            else if (input[i] == space[0])
            {
                if (cryptoSp == 1)
                {
                    output[i] = cryptoSpace[0];
                }
                else
                {
                    output[i] = space[0];
                }
            }
        }
    }

    printf("\nEncrypted message:\n> %s\n\n", output);

    system("pause");

    // TODO: make it read from and write to text file

    return 0;
}

void clearBuffer() {
    // Clear the input buffer
    int clearBuffer;
    while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF)
    { }
}

void cipherSpace(bool sp) {
    if (sp == 1)
    {
        printf("\nInput a character to be used instead of space:\n> ");
        scanf(" %1c", &cryptoSpace[0]);
        cryptoSp = 1;
    }
}