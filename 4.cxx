#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة تشفير Auto-Key Cipher
void encryptAutoKey(char *plaintext, char *ciphertext, char key) {
    int length = strlen(plaintext);
    char autoKey[length];  
    autoKey[0] = key; // المفتاح الأساسي لأول حرف

    for (int i = 1; i < length; i++) {
        autoKey[i] = plaintext[i - 1]; // استخدام الحروف السابقة كمفتاح
    }

    for (int i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) { // التأكد من أن الحرف أبجدي
            ciphertext[i] = ((toupper(plaintext[i]) - 'A') + (toupper(autoKey[i]) - 'A')) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // إبقاء الأحرف غير الأبجدية كما هي
        }
    }
    ciphertext[length] = '\0'; // إضافة null terminator
}

// دالة فك التشفير Auto-Key Cipher
void decryptAutoKey(char *ciphertext, char *decrypted, char key) {
    int length = strlen(ciphertext);
    char autoKey[length];  
    autoKey[0] = key; // المفتاح الأساسي لأول حرف

    for (int i = 0; i < length; i++) {
        if (isalpha(ciphertext[i])) {
            decrypted[i] = ((toupper(ciphertext[i]) - 'A') - (toupper(autoKey[i]) - 'A') + 26) % 26 + 'A';
            if (i + 1 < length) autoKey[i + 1] = decrypted[i]; // استخدام النص الأصلي المستعاد كمفتاح
        } else {
            decrypted[i] = ciphertext[i]; // إبقاء الأحرف غير الأبجدية كما هي
        }
    }
    decrypted[length] = '\0'; // إضافة null terminator
}

int main() {
    char plaintext[100], ciphertext[100], decrypted[100];
    char key;

    // إدخال النص الأصلي
    printf("أدخل النص الأصلي: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // إزالة السطر الجديد

    // إدخال المفتاح الأساسي
    printf("أدخل الحرف الأول للمفتاح: ");
    scanf(" %c", &key);
    key = toupper(key); // تحويل المفتاح إلى حرف كبير

    // تنفيذ التشفير
    encryptAutoKey(plaintext, ciphertext, key);
    
    // تنفيذ فك التشفير
    decryptAutoKey(ciphertext, decrypted, key);

    // طباعة النتائج
    printf("\n==== النتائج ====\n");
    printf("النص الأصلي: %s\n", plaintext);
    printf("النص المشفر: %s\n", ciphertext);
    printf("النص المفكوك التشفير: %s\n", decrypted);

    return 0;
}