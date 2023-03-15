/**
 * P167 分解质因数
*/

// 定理: 一个数 n 的质因数最多只会有一个数大于 sqrt(n)

#include <iostream>
#include <cmath>
#define MAXN 100000

using namespace std;

/**
 * 首先找到 MAXN 范围内的所有素数，保存到 primeArray 中
 * 素数筛法
 * return: the number of prime
*/
int findPrime(int primeArray[])
{
    bool isFiltered[MAXN] = {false};
    int primeNum = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (isFiltered[i] == false)
        {
            // 加入到 primeArray 中
            primeArray[primeNum++] = i;
            // 倍数全部被筛选
            for (int j = 2 * i; j <= MAXN; j += i)
            {
                isFiltered[j] = true;
            }
        }
    }

    return primeNum;
}

/**
 * 构造一个类或者结构体，用来存储质因子
*/
class Factor 
{
private: 
    // 底数
    int base;
    // 指数 
    int index;
public: 
    Factor() {}
    Factor(int _base, int _index): base(_base), index(_index) {};
    void setBase(int _base) { this->base = _base; }
    void setIndex(int _index) { this->index = _index; }
    int getBase() { return this->base; }
    int getIndex() { return this->index; }
    int value()
    {
        int result = 1;
        for (int i = 0; i < this->index; i++)
        {
            result *= this->base;
        }
        return result;
    }
};

/**
 * targetNum: 要分解的数
 * primeArray[]: 存储素数的数组
 * factorArray[]: 质因数数组
 * factorNum: 质因数个数
*/
// 定理: 一个数 n 的质因数最多只会有一个数大于 sqrt(n)
int  decomposePrimeFactor(int targetNum, int primeArray[], Factor factorArray[])
{
    int factorNum = 0;
    for (int i = 0; primeArray[i] < sqrt(targetNum); i++)
    {
        if (targetNum % primeArray[i] == 0)
        {
            factorArray[factorNum].setBase(primeArray[i]);
            factorArray[factorNum].setIndex(0);
            
            while (targetNum % primeArray[i] == 0)
            {
                // 指数 +1
                factorArray[factorNum].setIndex(factorArray[factorNum].getIndex() + 1);
                // 目标数除以质因子
                targetNum /= primeArray[i];
            }

            factorNum += 1;
        }
    }
    // 结束后如果 targetNum != 1，说明存在一个大于 sqrt(targetNum) 的质因子
    if (targetNum != 1)
    {
        factorArray[factorNum].setBase(targetNum);
        factorArray[factorNum].setIndex(1);

        targetNum /= targetNum;
        factorNum += 1;
    }

    return factorNum;
}

int main()
{
    // 首先获得 MAXN 范围内的所有素数
    int primeArray[MAXN + 1];
    int primeNum = findPrime(primeArray);
    // 质因数数组
    Factor *factorArray = new Factor[10];
    int targetNum;
    cout << "Input target number: ";
    cin >> targetNum;
    // 分解质因数
    int factorNum = decomposePrimeFactor(targetNum, primeArray, factorArray);
    // print
    cout << targetNum << " = ";
    for (int i = 0; i < factorNum; i++)
    {
        if (i > 0)
        {
            cout << " * ";
        }
        cout << factorArray[i].getBase();
        if (factorArray[i].getIndex() > 1)
        {
            cout << "^" << factorArray[i].getIndex();
        }  
    }
    cout << endl;

    return 0;
}