#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // لمسة التحقق من صحة الإزاحة

// دالة لتشفير حرف واحد باستخدام شفرة قيصر
char caesar_encrypt_char(char ch, int key) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((ch - base + key) % 26) + base);
    } else {
        return ch; // الحروف غير الأبجدية تبقى كما هي
    }
}

// دالة لفك تشفير حرف واحد باستخدام شفرة قيصر
char caesar_decrypt_char(char ch, int key) {
    return caesar_encrypt_char(ch, 26 - (key % 26)); // فك التشفير هو تشفير بإزاحة معاكسة
}

// دالة لتشفير نص كامل باستخدام شفرة قيصر
void caesar_encrypt(char *plaintext, int key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = caesar_encrypt_char(plaintext[i], key);
    }
    ciphertext[strlen(plaintext)] = '\0';
}

// دالة لفك تشفير نص كامل باستخدام شفرة قيصر
void caesar_decrypt(char *ciphertext, int key, char *plaintext) {
    caesar_encrypt(ciphertext, 26 - (key % 26), plaintext); // إعادة استخدام دالة التشفير بإزاحة معاكسة
}

int main() {
    char text[1000];
    char encrypted_text[1000];
    char decrypted_text[1000];
    int key;

    printf("أدخل النص: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // إزالة حرف السطر الجديد

    printf("أدخل مفتاح الإزاحة (عدد صحيح): ");
    if (scanf("%d", &key) != 1) {
        printf("إدخال غير صالح للمفتاح.\n");
        return 1;
    }
    // استهلاك أي أحرف متبقية في سطر الإدخال
    while (getchar() != '\n');

    caesar_encrypt(text, key, encrypted_text);
    printf("النص المشفر: %s\n", encrypted_text);

    caesar_decrypt(encrypted_text, key, decrypted_text);
    printf("النص المفكك: %s\n", decrypted_text);

    return 0;
}
