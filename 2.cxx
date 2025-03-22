#include <stdio.h>
#include <string.h>
#include <ctype.h>

// إيجاد المعكوس الضربي لـ a في modulo 26
int modInverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) return i;
    }
    return -1;
}

// دالة التشفير باستخدام Affine Cipher
void affineEncrypt(char *text, int a, int b, char *result) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result[i] = ((a * (text[i] - base) + b) % 26) + base;
        } else {
            result[i] = text[i];
        }
    }
    result[i] = '\0';
}

// دالة فك التشفير باستخدام Affine Cipher
void affineDecrypt(char *cipherText, int a, int b, char *result) {
    int i, a_inv = modInverse(a, 26);
    if (a_inv == -1) {
        printf("لا يوجد معكوس لـ a، استخدم قيمة أخرى.\n");
        return;
    }

    for (i = 0; cipherText[i] != '\0'; i++) {
        if (isalpha(cipherText[i])) {
            char base = isupper(cipherText[i]) ? 'A' : 'a';
            result[i] = ((a_inv * (cipherText[i] - base - b + 26)) % 26) + base;
        } else {
            result[i] = cipherText[i];
        }
    }
    result[i] = '\0';
}

// البرنامج الرئيسي
int main() {
    char text[100], cipherText[100], decryptedText[100];
    int a = 5, b = 8;  // القيم الافتراضية للمفتاح

    printf("أدخل النص المراد تشفيره: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    // التشفير
    affineEncrypt(text, a, b, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    // فك التشفير
    affineDecrypt(cipherText, a, b, decryptedText);
    printf("النص المفكوك التشفير: %s\n", decryptedText);

    return 0;
}