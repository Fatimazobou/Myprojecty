#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة لتشفير النص باستخدام Vigenère Cipher
void vigenereEncrypt(char *text, char *key, char *cipherText) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) { // فقط الحروف الأبجدية
            char base = isupper(text[i]) ? 'A' : 'a';
            cipherText[i] = (text[i] - base + (toupper(key[j % keyLen]) - 'A')) % 26 + base;
            j++; // تحريك المفتاح فقط عند وجود حرف مشفر
        } else {
            cipherText[i] = text[i]; // لا يتم تشفير الرموز الأخرى
        }
    }
    cipherText[i] = '\0';
}

// دالة لفك التشفير باستخدام Vigenère Cipher
void vigenereDecrypt(char *cipherText, char *key, char *plainText) {
    int textLen = strlen(cipherText);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(cipherText[i])) {
            char base = isupper(cipherText[i]) ? 'A' : 'a';
            plainText[i] = (cipherText[i] - base - (toupper(key[j % keyLen]) - 'A') + 26) % 26 + base;
            j++;
        } else {
            plainText[i] = cipherText[i];
        }
    }
    plainText[i] = '\0';
}

// البرنامج الرئيسي
int main() {
    char text[100], key[100], cipherText[100], decryptedText[100];

    printf("أدخل النص المراد تشفيره: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // حذف السطر الجديد من الإدخال

    printf("أدخل المفتاح: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    // التشفير
    vigenereEncrypt(text, key, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    // فك التشفير
    vigenereDecrypt(cipherText, key, decryptedText);
    printf("النص المفكوك التشفير: %s\n", decryptedText);

    return 0;
}