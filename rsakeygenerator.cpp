#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <cstdint>
#include <windows.h>
#include "lib.h"
#include <fstream>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    cout << "RSA Key Generator" << endl;
    cout << "素数の桁数を入力してください (1〜18): ";
    int digits;
    cin >> digits;

    if (digits <= 0 || digits > 18)
    {
        cout << "エラー: 桁数は1〜18の範囲で入力してください。" << endl;
        return 1;
    }

    // 指定桁数の範囲 [lower, upper]
    long long lower = (digits == 1) ? 2 : (long long)pow(10.0, digits - 1);
    long long upper = (long long)pow(10.0, digits) - 1;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<long long> dis(lower, upper);

    vector<long long> primes;
    while (primes.size() < 2)
    {
        long long candidate = dis(gen);
        // 奇数にする (2を除く偶数は素数でない)
        if (candidate != 2 && candidate % 2 == 0)
            candidate++;
        if (candidate > upper)
            continue;
        if (isPrime(candidate))
        {
            // 重複チェック
            bool dup = false;
            for (long long p : primes)
                if (p == candidate)
                {
                    dup = true;
                    break;
                }
            if (!dup)
                primes.push_back(candidate);
        }
    }
    ofstream out("keys.txt");
    out << "生成された素数 p: " << primes[0] << endl;
    out << "生成された素数 q: " << primes[1] << endl;
    out << "n = p * q = " << primes[0] * primes[1] << endl;
    const int n = primes[0] * primes[1];
    cout << "n = p * q: " << n << endl;
    const int phi = lcm(primes[0] - 1, primes[1] - 1);
    out << "φ(n) = lcm(p-1, q-1) = " << phi << endl;

    const int E = 17; // 公開指数
    cout << "公開指数 e: " << E << endl;
    out << "公開指数 e: " << E << endl;
    // 秘密指数 d を求める (d * E ≡ 1 (mod φ))
    int d = 0;
    for (int i = 1; i < phi; i++)
    {
        if ((E * i) % phi == 1)
        {
            d = i;
            break;
        }
    }
    out << "秘密指数 d: " << d << endl;
    out.close();
    return 0;
}