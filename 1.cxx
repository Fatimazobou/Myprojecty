#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة لتشفير وفك تشفير النص باستخدام Beaufort Cipher
void beaufortCipher(char *text, char *key, char *result) {
    int textLen = strlen(text);
    int keyLen = strlen(key);
    int i, j = 0;

    for (i = 0; i < textLen; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result[i] = ((toupper(key[j % keyLen]) - 'A' - (text[i] - base) + 26) % 26) + base;
            j++;
        } else {
            result[i] = text[i]; // الاحتفاظ بالرموز الأخرى كما هي
        }
    }
    result[i] = '\0';
}

// البرنامج الرئيسي
int main() {
    char text[100], key[100], cipherText[100], decryptedText[100];

    printf("أدخل النص المراد تشفيره: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("أدخل المفتاح: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    // التشفير
    beaufortCipher(text, key, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    // فك التشفير (نفس الدالة)
    beaufortCipher(cipherText, key, decryptedText);
    printf("النص المفكوك التشفير: %s\n", decryptedText);

    return 0;
}