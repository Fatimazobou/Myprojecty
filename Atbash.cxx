#include <stdio.h>
#include <ctype.h>
#include <string.h>

// دالة لتنفيذ عملية التشفير/فك التشفير باستخدام شفرة أتباش
void atbash(const char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (isalpha(c)) {  // إذا كان الحرف أبجديًا
            if (islower(c))
                output[i] = 'z' - (c - 'a');
            else
                output[i] = 'Z' - (c - 'A');
        } else {  // غير ذلك، يتم نسخه كما هو (أرقام، علامات، ..)
            output[i] = c;
        }
    }
    output[i] = '\0';  // إنهاء السلسلة
}

int main(void) {
    char text[1000];       // لتخزين النص المدخل من المستخدم
    char encrypted[1000];  // لتخزين النص المشفر
    char decrypted[1000];  // لتخزين النص المفكك

    printf("ادخل النص: ");
    fgets(text, sizeof(text), stdin);
    
    // إزالة نهاية السطر في حالة وجودها
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
    
    // تشفير النص
    atbash(text, encrypted);
    printf("النص المشفر: %s\n", encrypted);
    
    // فك التشفير، حيث تستخدم نفس الدالة (خاصية تبادلية)
    atbash(encrypted, decrypted);
    printf("النص بعد فك التشفير: %s\n", decrypted);
    
    return 0;
}