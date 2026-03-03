#include <iostream>
#include <windows.h>

#include "lib.h"

using namespace std;

// RSA復号化関数
long long decrypt(long long ciphertext, long long d, long long n)
{
    return powmod(ciphertext, d, n);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "RSA Decrypter" << endl;
    cout << "暗号文を入力してください: ";
    long long ciphertext;
    cin >> ciphertext;

    cout << "秘密鍵dを入力してください: ";
    long long d;
    cin >> d;

    cout << "モジュラスnを入力してください: ";
    long long n;
    cin >> n;

    long long plaintext = decrypt(ciphertext, d, n);
    cout << "復号化された平文: " << plaintext << endl;

    return 0;
}