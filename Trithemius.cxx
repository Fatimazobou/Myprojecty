#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void toUpperCase(char *text) {
    for (int i = 0; text[i]; i++) {
        text[i] = toupper(text[i]);
    }
}

char trithemiusEncryptChar(char c, int pos) {
    if (!isalpha(c)) return c;
    return ((c - 'A' + pos) % 26) + 'A';
}

char trithemiusDecryptChar(char c, int pos) {
    if (!isalpha(c)) return c;
    return ((c - 'A' - pos + 26) % 26) + 'A';
}

void trithemiusEncrypt(char *msg, char *res) {
    for (int i = 0; msg[i]; i++) {
        res[i] = trithemiusEncryptChar(msg[i], i);
    }
    res[strlen(msg)] = '\0';
}

void trithemiusDecrypt(char *msg, char *res) {
    for (int i = 0; msg[i]; i++) {
        res[i] = trithemiusDecryptChar(msg[i], i);
    }
    res[strlen(msg)] = '\0';
}

int main() {
    char message[MAX], encrypted[MAX], decrypted[MAX];

    printf("Entrer le message : ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0';

    toUpperCase(message);

    trithemiusEncrypt(message, encrypted);
    trithemiusDecrypt(encrypted, decrypted);

    printf("\nTexte chiffre   : %s", encrypted);
    printf("\nTexte dechiffre : %s\n", decrypted);

    return 0;
}
