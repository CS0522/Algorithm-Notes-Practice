/**
 * P436 最长回文子串
 * 动态规划
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// 输入 string 
string targetStr;
// dp array
// 里面只能是 1 或者 0
int **dp;

void init()
{
    cout << "Input the string: " << endl;
    getline(cin, targetStr);
    // initialize dp array
    dp = new int*[targetStr.length()];
    for (int i = 0; i < targetStr.length(); i++)
    {
        dp[i] = new int[targetStr.length()];
        for (int j = 0; j < targetStr.length(); j++)
        {
            dp[i][j] = 0;
        }
    }
}

void calPalindromic()
{
    // 记录当前最大回文子串的长度
    int maxLength = 1;
    // 设置边界条件
    for (int i = 0; i < targetStr.length(); i++)
    {
        // 长度为 1 的子串，最大回文串值为 1
        dp[i][i] = 1;
        // 长度为 2 的子串，如果 str[i] == str[i][i + 1]，最大回文串值为 2
        if (i < targetStr.length() - 1)
        {
            dp[i][i + 1] = (targetStr[i] == targetStr[i + 1]) ? 1 : 0;
            maxLength += 1; 
        }
    }
    // 状态转移
    // 按字符串的长度进行枚举
    for (int l = 3; l <= targetStr.length(); l++)
    {
        // 左端点 i
        // 右端点 i + l - 3
        for (int i = 0; i + l - 1 < targetStr.length(); i++)
        {
            if (targetStr[i] == targetStr[i + l - 1])
            {
                dp[i][i + l - 1] = dp[i + 1][i + l - 2];
                // 最大回文子串长度 update
                maxLength = l;
            }
            else 
            {
                dp[i][i + l - 1] = 0;
            }
        }
    }

    cout << "Max Palindromic length: " << maxLength << endl;
}

int main()
{
    init();
    calPalindromic();
    return 0;
}