#include <iostream>
#include <windows.h>
#include "lib.h"

using namespace std;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    long long n;
    cin >> n;
    cout << "inverse of 65537 mod λ(n): " << modinv(65537, n) << endl;
}