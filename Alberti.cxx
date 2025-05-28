#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// توليد المفتاح الكامل (مفتاح + نص)
void generateKey(char *text, char *key, char *fullKey) {
    int i, j = 0;
    fullKey[0] = toupper(key[0]); // أول حرف هو المفتاح
    for (i = 1; i < strlen(text); i++) {
        while (!isalpha(text[j])) j++; // تخطي الفراغات والرموز
        fullKey[i] = toupper(text[j]);
        j++;
    }
    fullKey[i] = '\0';
}

// التشفير
void encrypt(char *text, char *key, char *cipher) {
    for (int i = 0; text[i] != '\0'; i++) {
        char t = toupper(text[i]);
        if (isalpha(t)) {
            cipher[i] = ((t - 'A') + (key[i] - 'A')) % 26 + 'A';
        } else {
            cipher[i] = t;
        }
    }
    cipher[strlen(text)] = '\0';
}

// فك التشفير
void decrypt(char *cipher, char *keyChar, char *original) {
    int len = strlen(cipher);
    char dynamicKey[MAX];
    dynamicKey[0] = toupper(keyChar[0]); // المفتاح الأولي
    original[0] = ((toupper(cipher[0]) - dynamicKey[0] + 26) % 26) + 'A';

    // بناء المفتاح تدريجيًا باستخدام النص المفكوك
    for (int i = 1; i < len; i++) {
        dynamicKey[i] = original[i - 1];
        if (isalpha(cipher[i])) {
            original[i] = ((toupper(cipher[i]) - dynamicKey[i] + 26) % 26) + 'A';
        } else {
            original[i] = cipher[i];
        }
    }
    original[len] = '\0';
}

int main() {
    char text[MAX], key[2], fullKey[MAX];
    char encrypted[MAX], decrypted[MAX];

    printf("ادخل النص: ");
    fgets(text, sizeof(text), stdin);
    size_t len = strlen(text);
    if (text[len - 1] == '\n') text[len - 1] = '\0';

    printf("ادخل حرف كمفتاح: ");
    fgets(key, sizeof(key), stdin);
    if (key[strlen(key) - 1] == '\n') key[strlen(key) - 1] = '\0';

    generateKey(text, key, fullKey);
    encrypt(text, fullKey, encrypted);
    printf("النص المشفر: %s\n", encrypted);

    decrypt(encrypted, key, decrypted);
    printf("النص بعد فك التشفير: %s\n", decrypted);

    return 0;
}
