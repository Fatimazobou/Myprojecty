#include <stdio.h>
#include <math.h>

// دالة لإيجاد القاسم المشترك الأكبر (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// دالة لحساب الأسس (الرفع للقوة مع mod)
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// دالة لحساب المفتاح الخاص d
int modInverse(int e, int phi) {
    for (int d = 2; d < phi; d++) {
        if ((d * e) % phi == 1) {
            return d;
        }
    }
    return -1;
}

// البرنامج الرئيسي
int main() {
    int p, q, n, phi, e, d, message, cipherText, decryptedText;

    // اختيار عددين أوليين
    printf("أدخل عددين أوليين (p و q): ");
    scanf("%d %d", &p, &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    // اختيار e بحيث يكون gcd(e, phi) = 1
    printf("أدخل قيمة e (يجب أن يكون 1 < e < %d و gcd(e, %d) = 1): ", phi, phi);
    scanf("%d", &e);

    if (gcd(e, phi) != 1) {
        printf("القيمة e غير صحيحة. يجب أن تكون أولية مع %d.\n", phi);
        return 1;
    }

    // حساب d
    d = modInverse(e, phi);
    if (d == -1) {
        printf("لا يمكن حساب d. اختر e أخرى.\n");
        return 1;
    }

    printf("المفتاح العام: (n=%d, e=%d)\n", n, e);
    printf("المفتاح الخاص: (d=%d)\n", d);

    // إدخال الرسالة
    printf("أدخل رقم الرسالة (M) بحيث يكون أقل من %d: ", n);
    scanf("%d", &message);

    // التشفير: C = (M^e) mod n
    cipherText = modExp(message, e, n);
    printf("النص المشفر: %d\n", cipherText);

    // فك التشفير: M = (C^d) mod n
    decryptedText = modExp(cipherText, d, n);
    printf("النص المفكوك التشفير: %d\n", decryptedText);

    return 0;
}