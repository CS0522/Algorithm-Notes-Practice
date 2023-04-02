/**
 * P430 最大连续子序列和
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 储存序列
// dynamic array
int *A;
// 存放以 A[i] 结尾的连续序列的最大和
int *dp;

// init
void init(int &num)
{
    A = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> A[i];
    }

    dp = new int[num];
    dp[0] = A[0];
}

// iterative
void calMaxConstantSqSum(int &num)
{
    for (int i = 1; i < num; i++)
    {
        dp[i] = max(A[i], dp[i - 1] + A[i]);
    }
}

// print
void print(int &num)
{
    // result index
    int k = 0;
    for (int i = 0; i < num; i++)
    {
        if (dp[i] > dp[k])
        {
            k = i;
        }
    }
    // find max
    cout << "Max sum: " << dp[k] << endl;
}

int main()
{
    cout << "number of sequence: ";
    int num;
    cin >> num;
    init(num);
    calMaxConstantSqSum(num);
    print(num);
    return 0;
}