#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 2  // حجم مصفوفة المفتاح

// دالة لحساب المحدد لمصفوفة 2×2
int determinant(int matrix[SIZE][SIZE]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % 26;
}

// دالة لحساب النظير الضربي للمحدد (mod 26)
int modInverse(int det) {
    det = (det % 26 + 26) % 26;  // التأكد من أنه موجب
    for (int i = 1; i < 26; i++) {
        if ((det * i) % 26 == 1) return i;
    }
    return -1;
}

// دالة لحساب المصفوفة العكسية لمصفوفة 2×2 (mod 26)
void inverseMatrix(int key[SIZE][SIZE], int inverse[SIZE][SIZE]) {
    int det = determinant(key);
    int invDet = modInverse(det);
    
    if (invDet == -1) {
        printf("المفتاح غير قابل للعكس، استخدم مفتاحًا آخر.\n");
        return;
    }

    inverse[0][0] = (key[1][1] * invDet) % 26;
    inverse[1][1] = (key[0][0] * invDet) % 26;
    inverse[0][1] = (-key[0][1] * invDet) % 26;
    inverse[1][0] = (-key[1][0] * invDet) % 26;

    // التأكد من أن جميع العناصر موجبة
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (inverse[i][j] < 0) inverse[i][j] += 26;
        }
    }
}

// تحويل النص إلى أرقام
void textToNumbers(char text[], int numbers[]) {
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = toupper(text[i]) - 'A';
    }
}

// تحويل الأرقام إلى نص
void numbersToText(int numbers[], char text[]) {
    for (int i = 0; i < SIZE; i++) {
        text[i] = numbers[i] + 'A';
    }
    text[SIZE] = '\0';
}

// دالة لضرب مصفوفة 2×2 في متجه 2×1
void multiplyMatrix(int key[SIZE][SIZE], int input[SIZE], int output[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        output[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            output[i] += key[i][j] * input[j];
        }
        output[i] %= 26;  // نطبق mod 26
    }
}

// دالة تشفير النص باستخدام Hill Cipher
void hillEncrypt(char text[], int key[SIZE][SIZE], char cipherText[]) {
    int input[SIZE], output[SIZE];

    textToNumbers(text, input);
    multiplyMatrix(key, input, output);
    numbersToText(output, cipherText);
}

// دالة فك التشفير باستخدام Hill Cipher
void hillDecrypt(char cipherText[], int key[SIZE][SIZE], char decryptedText[]) {
    int input[SIZE], output[SIZE], inverseKey[SIZE][SIZE];

    inverseMatrix(key, inverseKey);
    textToNumbers(cipherText, input);
    multiplyMatrix(inverseKey, input, output);
    numbersToText(output, decryptedText);
}

// البرنامج الرئيسي
int main() {
    char text[SIZE + 1], cipherText[SIZE + 1], decryptedText[SIZE + 1];
    int key[SIZE][SIZE];

    printf("أدخل النص المراد تشفيره (%d أحرف فقط): ", SIZE);
    scanf("%s", text);

    printf("أدخل مفتاح التشفير (مصفوفة %dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &key[i][j]);

    // تشفير النص
    hillEncrypt(text, key, cipherText);
    printf("النص المشفر: %s\n", cipherText);

    // فك التشفير
    hillDecrypt(cipherText, key, decryptedText);
    printf("النص المفكوك التشفير: %s\n", decryptedText);

    return 0;
}