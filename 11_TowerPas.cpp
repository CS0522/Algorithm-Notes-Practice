/**
 * P427 数塔问题
 * 动态规划
*/

#include <iostream>
#include <algorithm>
#define MAXN 1000
using namespace std;

// 存储数塔
int towerPas[MAXN][MAXN];
// 存储某个点到最底层路径的最大和
int dp[MAXN][MAXN];

// 初始化数塔
void init(int &floorNum)
{
    cout << "Input tower data: " << endl;
    for (int i = 1; i <= floorNum; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> towerPas[i][j];
        }
    }
}

// 迭代求解
void iterativeDP(int &floorNum)
{
    // 最底层的 dp 的值等于 towerPas
    // 最底层的个数 == floorNum
    for (int i = 1; i <= floorNum; i++)
    {
        dp[floorNum][i] = towerPas[floorNum][i];
    }

    // 从下至上将 dp 进行更新
    for (int i = floorNum - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            // 状态转移方程
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + towerPas[i][j];
        }
    }
}

// 递归求解
int recursiveDP(int &floorNum, int currentFloor, int currentNum)
{
    // 边界
    if (currentFloor == floorNum)
    {
        dp[currentFloor][currentNum] = towerPas[currentFloor][currentNum];
        return dp[currentFloor][currentNum];
    }
    // 从上至下将 dp 进行更新
    dp[currentFloor][currentNum] = max(recursiveDP(floorNum, currentFloor + 1, currentNum), 
                                        recursiveDP(floorNum, currentFloor + 1, currentNum + 1)) 
                                        + towerPas[currentFloor][currentNum];
    return dp[currentFloor][currentNum];
}

int main()
{
    cout << "Input floor numbers of the tower: ";
    int floorNum;
    cin >> floorNum;
    init(floorNum);
    // iterativeDP(floorNum);
    dp[1][1] = recursiveDP(floorNum, 1, 1);
    cout << "Maximum sum: " << dp[1][1] << endl;
    return 0;
}