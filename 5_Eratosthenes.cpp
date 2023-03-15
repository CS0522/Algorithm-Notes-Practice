/**
 * P162 素数筛法
*/
#include <iostream>
#include <cmath>
using namespace std;

// 判断 n 是否为素数（普通）
bool isPrime(int n)
{
    if (n < 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 素数筛法
/**
 * maxn: 1~maxn 内的素数
 * primeArray[]: 存放素数的数组
 * return: 所有素数的个数（数组有效长度的下一位的下标）
*/
int findPrime(int maxn, int primeArray[])
{
    int primeNum = 0;
    // 新建一个 bool 数组用于记录是否被筛选
    bool *hasFiltered = new bool[maxn + 1];
    for (int i = 0; i <= maxn; i++)
    {
        hasFiltered[i] = false;
    }

    for (int i = 2; i <= maxn; i++)
    {
        if (hasFiltered[i] == false)
        {
            // 加入到 primeArray 数组中
            primeArray[primeNum++] = i;
            // 筛选所有 i 的倍数
            for (int j = 2 * i; j <= maxn; j += i)
            {
                // 都被筛选了出来
                hasFiltered[j] = true;
            }
        }
    }

    return primeNum;
}

int main()
{
    // 求出 1~maxn 内的素数
    int maxn;
    cout << "Input maxn: ";
    cin >> maxn;
    int *primeArray = new int[maxn + 1];

    int primeNum = findPrime(maxn, primeArray);
    //print
    cout << "Prime numbers are: " << endl; 
    for (int i = 0; i < primeNum; i++)
    {
        cout << primeArray[i] << " ";
    }
    cout << endl;

    return 0;
}