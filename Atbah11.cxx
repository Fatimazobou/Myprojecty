#include <stdio.h>
#include <string.h>
#include <ctype.h>

// دالة لتشفير/فك تشفير نص إنجليزي باستخدام طريقة Atbah
void atbah_english(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'Z' - (text[i] - 'A');
            } else {
                text[i] = 'z' - (text[i] - 'a');
            }
        }
    }
}

int main() {
    char text[100];

    printf("Enter the English text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline

    printf("Original text: %s\n", text);

    atbah_english(text);
    printf("Encrypted text (Atbah): %s\n", text);

    atbah_english(text); // Decrypt by applying the same function again
    printf("Decrypted text (Atbah): %s\n", text);

    return 0;
}