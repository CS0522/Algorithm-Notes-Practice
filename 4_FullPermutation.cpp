/**
 * P115 全排列 递归
*/

#include <iostream>
#define MAXN 10
using namespace std;

int n;
int permutationArray[MAXN];
bool hashTable[MAXN] = {false};

void fullPermutationFunc(int index)
{
    // 当 permutationArray 有 n 个元素了，结束递归
    // index == n + 1. 递归边界，已经处理完前 1~n 位
    if (index == n + 1)
    {
        // print
        for (int i = 0; i < n; i++)
        {
            cout << permutationArray[i + 1];
        }
        cout << endl;

        return;
    }

    // 还没有处理完
    else
    {
        // 循环检查，是否已经放在了 permutaionArray 中
        for (int i = 1; i <= n; i++)
        {
            // 在 permutationArray 中，继续循环
            // 不在 permutaionArray 中
            if (hashTable[i] == false)
            {
                // 加入到 permutationArray 中
                permutationArray[index] = i;
                // 设置为 true
                hashTable[i] = true;
                // 递归执行 index 后面的排序
                fullPermutationFunc(index + 1);
                // 执行完后，清除 index 位，进行下一个数的全排列
                hashTable[i] = false;
            }
        }
    }   
}

int main()
{
    cout << "Input n: ";
    cin >> n;
    while (n >= MAXN)
    {
        cout << "Too big. Input again: ";
        cin >> n;
    }
    // 从1开始
    fullPermutationFunc(1);
    
    return 0;
}