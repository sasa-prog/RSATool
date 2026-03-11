#include <iostream>
#include <windows.h>
#include <chrono>

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

    auto start = std::chrono::high_resolution_clock::now();
    long long plaintext = decrypt(ciphertext, d, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "復号化された平文: " << plaintext << endl;
    cout << "処理時間: " << time << " ms" << endl;

    return 0;
}