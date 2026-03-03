#ifndef INCLUDE
#define INCLUDE
#include <initializer_list>

// オーバーフローを防ぐ安全な乗算剰余 (a * b) % m
long long mulmod(long long a, long long b, long long m)
{
    long long result = 0;
    a %= m;
    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % m;
        a = (a * 2) % m;
        b >>= 1;
    }
    return result;
}

// 冪乗剰余 base^exp % mod
long long powmod(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin 素数判定 (決定論的: n < 3.3 * 10^24 に対して正確)
bool isPrime(long long n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
        return false;

    // n-1 = 2^r * d に変換
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0)
    {
        d /= 2;
        r++;
    }

    // 決定論的な検査用基底 (64ビット整数全域で正確)
    for (long long a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (a >= n)
            continue;
        long long x = powmod(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool composite = true;
        for (int i = 0; i < r - 1; i++)
        {
            x = mulmod(x, x, n);
            if (x == n - 1)
            {
                composite = false;
                break;
            }
        }
        if (composite)
            return false;
    }
    return true;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
#endif