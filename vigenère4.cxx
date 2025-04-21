#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// توليد المفتاح الكامل
void generateKey(char *text, char *key, char *newKey) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    for (int i = 0, j = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            newKey[i] = toupper(key[j % keyLen]);
            j++;
        } else {
            newKey[i] = text[i]; // احتفظ بالمسافات والعلامات
        }
    }
    newKey[textLen] = '\0';
}

// التشفير
void encrypt(char *text, char *key, char *cipher) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            cipher[i] = ((toupper(c) - 'A') + (key[i] - 'A')) % 26 + 'A';
        } else {
            cipher[i] = c;
        }
    }
    cipher[strlen(text)] = '\0';
}

// فك التشفير
void decrypt(char *cipher, char *key, char *text) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        char c = cipher[i];
        if (isalpha(c)) {
            text[i] = ((toupper(c) - key[i] + 26) % 26) + 'A';
        } else {
            text[i] = c;
        }
    }
    text[strlen(cipher)] = '\0';
}

int main() {
    char text[MAX], key[MAX], fullKey[MAX];
    char encrypted[MAX], decrypted[MAX];

    printf("ادخل النص: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (text[len - 1] == '\n') text[len - 1] = '\0';

    printf("ادخل كلمة المفتاح: ");
    fgets(key, sizeof(key), stdin);
    len = strlen(key);
    if (key[len - 1] == '\n') key[len - 1] = '\0';

    // توليد المفتاح الكامل
    generateKey(text, key, fullKey);

    // تشفير النص
    encrypt(text, fullKey, encrypted);
    printf("النص المشفر: %s\n", encrypted);

    // فك التشفير
    decrypt(encrypted, fullKey, decrypted);
    printf("النص بعد فك التشفير: %s\n", decrypted);

    return 0;
}