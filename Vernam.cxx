#include <stdio.h>
#include <string.h>

#define MAX 1000

void vernamEncryptDecrypt(char *message, char *key, char *result) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        result[i] = message[i] ^ key[i];  // XOR
    }
    result[len] = '\0';
}

int main() {
    char message[MAX], key[MAX], encrypted[MAX], decrypted[MAX];

    printf("Entrer le message : ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0';

    int len = strlen(message);

    printf("Entrer la cle (meme longueur que le message) : ");
    fgets(key, MAX, stdin);
    key[strcspn(key, "\n")] = '\0';

    if (strlen(key) != len) {
        printf("Erreur: La cle doit avoir la meme longueur que le message.\n");
        return 1;
    }

    // Chiffrement
    vernamEncryptDecrypt(message, key, encrypted);

    // Déchiffrement
    vernamEncryptDecrypt(encrypted, key, decrypted);

    printf("\nTexte chiffre (brut - peut contenir des caracteres non lisibles) : ");
    for (int i = 0; i < len; i++) {
        printf("%02X ", (unsigned char)encrypted[i]);
    }

    printf("\nTexte dechiffre : %s\n", decrypted);

    return 0;}
