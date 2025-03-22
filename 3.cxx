#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة لتشفير النص باستخدام Atbash
void atbashCipher(char *text, char *result) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            result[i] = base + ('Z' - text[i]); 
        } else {
            result[i] = text[i]; // الاحتفاظ بالرموز كما هي
        }
    }
    result[i] = '\0';
}

// البرنامج الرئيسي
int main() {
    char text[100], cipherText[100];

    printf("أدخل النص المراد تشفيره: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    // التشفير وفك التشفير بنفس الدالة
    atbashCipher(text, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    atbashCipher(cipherText, text);  // إعادة التشفير لفك التشفير
    printf("النص المفكوك التشفير: %s\n", text);

    return 0;
}