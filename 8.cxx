#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// توليد مفتاح عشوائي بطول النص
void generateKey(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = 'A' + (rand() % 26);  // اختيار حرف عشوائي من A إلى Z
    }
    key[length] = '\0';
}

// تشفير النص باستخدام XOR
void oneTimePadEncrypt(char *text, char *key, char *cipherText) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        cipherText[i] = ((text[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    cipherText[length] = '\0';
}

// فك التشفير باستخدام XOR
void oneTimePadDecrypt(char *cipherText, char *key, char *decryptedText) {
    int length = strlen(cipherText);
    for (int i = 0; i < length; i++) {
        decryptedText[i] = ((cipherText[i] - 'A') ^ (key[i] - 'A')) + 'A';
    }
    decryptedText[length] = '\0';
}

// البرنامج الرئيسي
int main() {
    char text[MAX_LEN], key[MAX_LEN], cipherText[MAX_LEN], decryptedText[MAX_LEN];

    srand(time(NULL)); // تهيئة مولد الأرقام العشوائية

    printf("أدخل النص المراد تشفيره (حروف A-Z فقط): ");
    scanf("%s", text);

    int length = strlen(text);
    generateKey(key, length);

    printf("المفتاح العشوائي: %s\n", key);

    // تشفير النص
    oneTimePadEncrypt(text, key, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    // فك التشفير
    oneTimePadDecrypt(cipherText, key, decryptedText);
    printf("النص المفكوك التشفير: %s\n", decryptedText);

    return 0;
}