/**
 * P434 最长公共子序列
 * 动态规划
 * 还是就考虑右端点
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 字符串
string strA;
string strB;

// dp 数组
int **dp;

// init
void init()
{
    cout << "Input the 2 string: " << endl;
    getline(cin, strA);
    getline(cin, strB);
    // initialize dp
    // dp[i][j]，i 是 strA 长度，j 是 strB 长度
    dp = new int*[strA.length() + 1];
    for (int i = 0; i <= strA.length(); i++)
    {
        dp[i] = new int[strB.length() + 1];
    }
    // 边界
    for (int i = 0; i <= strA.length(); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= strB.length(); j++)
    {
        dp[0][j] = 0;
    }
}

// main function
void calLCS()
{
    for (int i = 1; i <= strA.length(); i++)
    {
        for (int j = 1; j <= strB.length(); j++)
        {
            // 状态转移方程
            if (strA[i] == strB[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void print()
{
    cout << "LCS is: " << dp[strA.length()][strB.length()] << endl;
}

int main()
{
    init();
    calLCS();
    print();
    return 0;
}