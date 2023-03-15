/**
 * P121 组最小数 简单贪心
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int makeMinFunc()
{
    // init stack
    stack<int> tempStack;
    stack<int> resultStack;
    int amount[10];
    cout << "Input the amount of each number: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> amount[i];
    }
    // 最高位不能是 0，从 1~9 中选取最小且 amount[i] != 0
    for (int j = 1; j < 10; j++)
    {
        if (amount[j] != 0)
        {
            // push
            tempStack.push(j);
            amount[j] -= 1;

            break;
        }
    }
    // 剩余位
    for (int k = 0; k < 10; k++)
    {
        // 当 k 的个数不止一个
        for (int l = 0; l < amount[k]; l++)
        {
            tempStack.push(k);
        }
    }

    // 顺序交换
    while (!tempStack.empty())
    {
        resultStack.push(tempStack.top());
        tempStack.pop();
    }

    // 最后，高位在栈底，末位在栈顶
    int result = 0;
    while (!resultStack.empty())
    {
        result *= 10;
        result += resultStack.top();
        resultStack.pop();
    }

    return result;
}

int main()
{
    cout << "The minimum number is: " << makeMinFunc() << endl;

    return 0;
}