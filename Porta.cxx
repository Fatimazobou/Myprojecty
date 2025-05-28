#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة لتشفير نص باستخدام طريقة Porta
void porta_encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    for (i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char key_char = toupper(key[i % key_len]);
            int row = key_char - 'A';
            int col = toupper(plaintext[i]) - 'A';
            ciphertext[i] = (row % 2 == 0) ? 'A' + (col + row) % 26 : 'A' + (col + 13 + row) % 26;
            if (islower(plaintext[i])) {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintext_len] = '\0';
}

// دالة لفك تشفير نص باستخدام طريقة Porta
void porta_decrypt(char *ciphertext, char *key, char *decryptedtext) {
    int i, j;
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    for (i = 0; i < ciphertext_len; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            char key_char = toupper(key[i % key_len]);
            int row = key_char - 'A';
            int col = toupper(ciphertext[i]) - 'A';
            int shift = (row % 2 == 0) ? row : row + 13;
            decryptedtext[i] = 'A' + (col - shift + 26) % 26;
            if (islower(ciphertext[i])) {
                decryptedtext[i] = tolower(decryptedtext[i]);
            }
        } else {
            decryptedtext[i] = ciphertext[i];
        }
    }
    decryptedtext[ciphertext_len] = '\0';
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    char decryptedtext[100];

    // إدخال النص المراد تشفيره
    printf("أدخل النص المراد تشفيره: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // إزالة حرف السطر الجديد

    // إدخال مفتاح التشفير
    printf("أدخل مفتاح التشفير: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; // إزالة حرف السطر الجديد

    // تشفير النص
    porta_encrypt(plaintext, key, ciphertext);
    printf("النص المشفر: %s\n", ciphertext);

    // فك تشفير النص المشفر
    porta_decrypt(ciphertext, key, decryptedtext);
    printf("النص المفكك: %s\n", decryptedtext);

    return 0;
}
