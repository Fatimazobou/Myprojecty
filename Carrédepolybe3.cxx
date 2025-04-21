#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

char square[5][5] = {
    {'A','B','C','D','E'},
    {'F','G','H','I','K'}, // I و J معاً
    {'L','M','N','O','P'},
    {'Q','R','S','T','U'},
    {'V','W','X','Y','Z'}
};

// البحث عن موقع الحرف في المربع
void findPosition(char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // دمج I و J
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (square[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// التشفير: نحول كل حرف إلى رقمين
void encryptPolybe(const char *text, char *encrypted) {
    int k = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = toupper(text[i]);
        if (ch >= 'A' && ch <= 'Z') {
            int row, col;
            findPosition(ch, &row, &col);
            encrypted[k++] = '1' + row;
            encrypted[k++] = '1' + col;
        }
        else if (ch == ' ') {
            encrypted[k++] = ' ';
        }
    }
    encrypted[k] = '\0';
}

// فك التشفير: كل رقمين يمثلان حرفاً
void decryptPolybe(const char *encrypted, char *decrypted) {
    int k = 0;
    for (int i = 0; encrypted[i] != '\0'; ) {
        if (isdigit(encrypted[i]) && isdigit(encrypted[i + 1])) {
            int row = encrypted[i] - '1';
            int col = encrypted[i + 1] - '1';
            decrypted[k++] = square[row][col];
            i += 2;
        } else if (encrypted[i] == ' ') {
            decrypted[k++] = ' ';
            i++;
        } else {
            i++; // تجاهل أي رمز غير متوقع
        }
    }
    decrypted[k] = '\0';
}

int main() {
    char text[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];

    printf("ادخل النص: ");
    fgets(text, sizeof(text), stdin);

    // حذف نهاية السطر
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
        text[len - 1] = '\0';

    encryptPolybe(text, encrypted);
    printf("النص بعد التشفير: %s\n", encrypted);

    decryptPolybe(encrypted, decrypted);
    printf("النص بعد فك التشفير: %s\n", decrypted);

    return 0;
}