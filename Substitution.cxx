#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// مفتاح التشفير (يجب أن يكون permutation من A إلى Z)
char substitution[26] = {
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z',
    'X', 'C', 'V', 'B', 'N', 'M'
};

// دالة لفك التشفير
void buildReverseSubstitution(char reverse[26]) {
    for (int i = 0; i < 26; i++) {
        reverse[substitution[i] - 'A'] = 'A' + i;
    }
}

void toUpperCase(char *text) {
    for (int i = 0; text[i]; i++)
        text[i] = toupper(text[i]);
}

void substituteEncrypt(char *text, char *result) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i]))
            result[i] = substitution[text[i] - 'A'];
        else
            result[i] = text[i];  // non-alpha remains
    }
    result[strlen(text)] = '\0';
}

void substituteDecrypt(char *text, char *result) {
    char reverse[26];
    buildReverseSubstitution(reverse);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i]))
            result[i] = reverse[text[i] - 'A'];
        else
            result[i] = text[i];
    }
    result[strlen(text)] = '\0';
}

int main() {
    char message[MAX], encrypted[MAX], decrypted[MAX];

    printf("Entrer le message : ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0';

    toUpperCase(message);

    substituteEncrypt(message, encrypted);
    substituteDecrypt(encrypted, decrypted);

    printf("\nTexte chiffre   : %s", encrypted);
    printf("\nTexte dechiffre : %s\n", decrypted);

    return 0;
}
