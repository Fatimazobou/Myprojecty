#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void toUpperCase(char *text) {
    for (int i = 0; text[i]; i++)
        text[i] = toupper(text[i]);
}

void beaufortCipher(char *text, char *key, char *result) {
    int len = strlen(text);
    int keyLen = strlen(key);
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            char keyChar = toupper(key[i % keyLen]);
            char textChar = toupper(text[i]);
            result[i] = (keyChar - textChar + 26) % 26 + 'A';
        } else {
            result[i] = text[i];  // keep non-alpha as is
        }
    }
    result[len] = '\0';
}

int main() {
    char message[MAX], key[MAX], encrypted[MAX], decrypted[MAX];

    printf("Entrer le message : ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Entrer la cle : ");
    fgets(key, MAX, stdin);
    key[strcspn(key, "\n")] = '\0';

    toUpperCase(message);
    toUpperCase(key);

    // Chiffrement
    beaufortCipher(message, key, encrypted);

    // Dechiffrement (même fonction)
    beaufortCipher(encrypted, key, decrypted);

    printf("\nTexte chiffre   : %s", encrypted);
    printf("\nTexte dechiffre : %s\n", decrypted);

    return 0;
}
