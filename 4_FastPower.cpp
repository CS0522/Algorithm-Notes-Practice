/**
 * P135 快速幂
*/

#include <iostream>
using namespace std;

typedef long long LL;

// (a^b) % mod
LL fastPowerFunc(LL a, LL b, LL mod)
{
    // 边界条件
    if (b == 0)
    {
        return 1;
    }

    if (b % 2 == 1)
    {
        return a * fastPowerFunc(a, b - 1, mod) % mod;
    }
    else
    {
        LL temp = fastPowerFunc(a, b / 2, mod);
        return temp * temp % mod;
    }
}

int main()
{
    cout << fastPowerFunc(5, 2, 3) << endl;
    return 0;
}