/**
 * P273 DFS 选取平方和最大的方案
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 序列 A 中 n 个数，选取 k 个数使得和为 x，同时最大平方和为 maxSquareSum
int n;
int k;
int x;
int maxSquareSum = -1;
int *array = new int[n + 1];

// temp 存放临时方案，result 存放平方和最大方案
vector<int> temp;
vector<int> result;

/**
 * index: 当前要处理 index 号整数
 * currentK: 当前已选整数 K
 * currentSum: 当前整数和
 * currentSquareSum: 当前整数平方和
*/
void DFS(int index, int currentK, int currentSum, int currentSquareSum)
{
    if (currentK == k && currentSum == x)
    {
        if (currentSquareSum > maxSquareSum)
        {
            maxSquareSum = currentSquareSum;
            // 更新最优方案
            result = temp;
        }
    }
    // 已经处理完 n 个数，或者超过 k 个数，或者和超过 x
    if (index >= n || currentK > k || currentSum > x)
    {
        return;
    }
    // 选 index 号整数
    temp.push_back(array[index]);
    DFS(index + 1, currentK + 1, currentSum + array[index], currentSquareSum + array[index] * array[index]);
    temp.pop_back();
    // 不选 index 号整数
    DFS(index + 1, currentK, currentSum, currentSquareSum);
}

int main()
{
    cout << "Input n, k, x: ";
    cin >> n >> k >> x;
    cout << "Input array(n numbers): " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    DFS(0, 0, 0, 0);
    // print result
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    delete [] array;
    
    return 0;
}