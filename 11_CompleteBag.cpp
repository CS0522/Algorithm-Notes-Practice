/**
 * P446 完全背包问题
 * 动态规划
 * 每种物品都有无穷件
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// weight array
int *weight;
// value array
int *value;
// dp array
// 前 i 件物品恰好装入容量为 v 的背包中，所能获得的最大价值
int **dp;
// improved dp array
int *dpImprove;

// init
void init(int &num, int &maxV)
{
    weight = new int[num + 1];
    value = new int[num + 1];
    dp = new int*[num + 1];
    dpImprove = new int[maxV + 1];
    for (int i = 0; i <= num; i++)
    {
        dp[i] = new int[maxV + 1];
    }
    cout << "Input weight: " << endl;
    // input weight
    for (int i = 1; i <= num; i++)
    {
        cin >> weight[i];
    }
    cout << "Input value: " << endl;
    // input value
    for (int i = 1; i <= num; i++)
    {
        cin >> value[i];
    }
}

// main function
void calMaxVal(int &num, int &maxV)
{
    // 边界
    for (int v = 0; v <= maxV; v++)
    {
        dp[0][v] = 0;
    }
    // 状态转移
    for (int i = 1; i <= num; i++)
    {
        for (int v = weight[i]; v <= maxV; v++)
        {
            // 不放 i，放 i 
            dp[i][v] = max(dp[i - 1][v], dp[i][v - weight[i]] + value[i]);
        }
    }
}

// improve space complexity
void calMaxValImprove(int &num, int &maxV)
{
    // 边界
    for (int v = 0; v <= maxV; v++)
    {
        dpImprove[v] = 0;
    }
    // 状态转移
    for (int i = 1; i <= num; i++)
    {
        // 完全背包问题，需要正序
        // 必须保证 [v - weight[i]] 是更新后的值
        for (int v = weight[i]; v <= maxV; v++)
        {
            dpImprove[v] = max(dpImprove[v], dpImprove[v - weight[i]] + value[i]);
        }
    }
}

// print result
void print(int &num, int &maxV)
{
    int result = 0;
    for (int i = 1; i <= num; i++)
    {
        for (int v = weight[i]; v <= maxV; v++)
        {
            if (dp[i][v] > result)
            {
                result = dp[i][v];
            }
        }
    }

    cout << "Max value is: " << result << endl;
}

void printImprove(int &num, int &maxV)
{
    int result = 0;
    for (int v = 0; v <= maxV; v++)
    {
        if (dpImprove[v] > result)
        {
            result = dpImprove[v];
        }
    }

    cout << "Max value is: " << result << endl;
}

int main()
{
    cout << "Input the number of matters and the max volume: ";
    int num, maxV;
    cin >> num >> maxV;
    init(num, maxV);
    // calMaxVal(num, maxV);
    // print(num, maxV);
    calMaxValImprove(num, maxV);
    printImprove(num, maxV);
    return 0;
}