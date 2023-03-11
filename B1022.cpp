/**
 * P94 进制转换
*/

#include <iostream>
#include <stack>
using namespace std;

int changeFunc(int value1, int value2, int product)
{
    int sum = value1 + value2;
    // initialize a stack
    stack<int> modStack;
    // 转换为D进制数
    while (sum != 0)
    {
        modStack.push(sum % product);
        sum /= product;
    }
    // 循环输出stack中的数 (余数)
    int result = 0;
    while (!modStack.empty())
    {
        // 为了输出格式
        result *= 10;

        result += modStack.top();
        modStack.pop();
    }

    return result;
}

int main()
{
    int value1, value2;
    // 进制数
    int product;
    cout << "Input A, B: ";
    cin >> value1 >> value2;
    cout << "Input D: ";
    cin >> product;
    int result = changeFunc(value1, value2, product);
    cout << "Output: " << result << endl;

    return 0;
}