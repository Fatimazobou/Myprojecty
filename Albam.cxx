#include <stdio.h>
#include <ctype.h>
#include <string.h>

// دالة لتنفيذ عملية التشفير/فك التشفير باستخدام شفرة ROT13 (Albam)
void rot13(const char *input, char *output) {
    int i;
    for(i = 0; input[i] != '\0'; i++){
        char c = input[i];
        if(isalpha(c)) {
            if(islower(c)) {
                // إذا كان الحرف صغيراً، نحول من 'a' إلى 'z'
                if(c >= 'a' && c <= 'm')
                    output[i] = c + 13;
                else
                    output[i] = c - 13;
            } else { // للحروف الكبيرة
                if(c >= 'A' && c <= 'M')
                    output[i] = c + 13;
                else
                    output[i] = c - 13;
            }
        } else {
            // باقي الرموز والأرقام تبقى كما هي
            output[i] = c;
        }
    }
    output[i] = '\0';  // إنهاء سلسلة الأحرف
}

int main(void) {
    char text[1000];       // لتخزين النص الأصلي المدخل من المستخدم
    char encrypted[1000];  // لتخزين النص المشفر
    char decrypted[1000];  // لتخزين النص بعد فك التشفير

    printf("ادخل النص: ");
    fgets(text, sizeof(text), stdin);
    
    // إزالة نهاية السطر في حال وجودها
    size_t len = strlen(text);
    if(len > 0 && text[len-1] == '\n') {
        text[len-1] = '\0';
    }
    
    // تشفير النص باستخدام ROT13 (Albam)
    rot13(text, encrypted);
    printf("النص بعد التشفير: %s\n", encrypted);
    
    // فك التشفير بإعادة تطبيق نفس الدالة (خاصية تبادلية)
    rot13(encrypted, decrypted);
    printf("النص بعد فك التشفير: %s\n", decrypted);
    
    return 0;
}
