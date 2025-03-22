#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// دالة لتوليد مفتاح عشوائي بنفس طول النص
void generateKey(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;  // توليد عدد عشوائي بين 0 و 255
    }
}

// دالة للتشفير وفك التشفير باستخدام XOR
void vernamCipher(char *text, char *key, char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = text[i] ^ key[i]; // تطبيق XOR بين النص والمفتاح
    }
}

int main() {
    srand(time(NULL)); // تهيئة مولد الأعداد العشوائية

    char text[100];
    printf("أدخل النص المراد تشفيره: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // إزالة السطر الجديد

    int length = strlen(text);
    char key[length], encrypted[length], decrypted[length];

    // توليد المفتاح العشوائي
    generateKey(key, length);

    // تشفير النص
    vernamCipher(text, key, encrypted, length);

    // فك التشفير
    vernamCipher(encrypted, key, decrypted, length);

    // طباعة النتائج
    printf("\n==== النتائج ====\n");
    printf("النص الأصلي: %s\n", text);

    printf("المفتاح المستخدم: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", (unsigned char)key[i]);
    }
    printf("\n");

    printf("النص المشفر: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", (unsigned char)encrypted[i]);
    }
    printf("\n");

    printf("النص المفكوك التشفير: %s\n", decrypted);

    return 0;
}