#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "lib.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int n;
    cin >> n;
    int p, q;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0 && i != 1 && i != n)
        {
            p = i;
            q = n / i;
            cout << p << " " << q << endl;
            break;
        }
    }
    long long lamda = lcm(p - 1, q - 1);
    cout << "λ(n): " << lamda << endl;
    long long e;
    cout << "公開鍵eを入力してください: ";
    cin >> e;
    long long d = modinv(e, lamda);
    cout << "秘密鍵d: " << d << endl;
    return 0;
}