/**
 * P432 最长不下降子序列
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 元序列
vector<int> numSq;
// 存储以某点为右端点的最长不下降子序列长度
vector<int> dp;

void init()
{
    cout << "Input the number of numSq: ";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        numSq.push_back(temp);
        // 设置每个的最长长度初始为 1 
        dp.push_back(1);
    }
}

// main function
void calLIS()
{
    for (int i = 0; i < numSq.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (numSq[i] >= numSq[j] && (dp[j] + 1 > dp[i]))
            {
                // 更新
                dp[i] = dp[j] + 1;
            }
        }
    }
}

void print()
{
    int result = 0;
    for (int i = 0; i < numSq.size(); i++)
    {
        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    cout << "LIS: " << result << endl;
}

int main()
{
    init();
    calLIS();
    print();
    return 0;
}