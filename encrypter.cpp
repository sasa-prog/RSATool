#include "lib.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "Encrypter" << endl;
    cout << "ランダムな整数を暗号化します" << endl;
    srand((unsigned)time(NULL));
    int m = rand() % 1000 + 1; // 1〜1000のランダムな整数
    ofstream out("plain.txt");
    out << "平文：" << m << endl;
    out.close();
    cout << "公開鍵 (n, e) を入力してください (スペース区切り): ";
    int n, e;
    cin >> n >> e;
    // 暗号化: c = m^e mod n
    int c = powmod(m, e, n);
    cout << "暗号文: " << c << endl;
    return 0;
}