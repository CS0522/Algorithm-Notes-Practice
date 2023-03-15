/**
 * P155-156 最大公约数、最小公倍数
 * 辗转相除法
 * gcd(a, b) = gcd(b, a % b)
 * lcm(a, b) = (a * b) / d
*/
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cout << "Input two numbers: ";
    int a, b;
    cin >> a >> b;
    int gcdResult = a > b ? gcd(a, b) : gcd(b, a);
    // 防止 a * b 超出 int 范围
    int lcmResult = (a / gcdResult) * b;
    cout << "The greatest common divisor is: " << gcdResult << endl;
    cout << "The least common multiple is: " << lcmResult << endl;

    return 0;
}