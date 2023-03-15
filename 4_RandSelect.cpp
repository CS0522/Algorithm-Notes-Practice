/**
 * P149 随机选择算法 返回第 K 大的数
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// 随机选取 pivot，进行划分
int randPartition(int array[], int left, int right)
{
    // 生成 [left, right] 内的随机数
    int p = (round(1.0 * rand() / RAND_MAX * (right - left)) + left);
    // 把 p 下标的值和 left 下标的值进行互换，然后直接套用普通的 partition of QuickSort
    swap(array[p], array[left]);

    int i = left;
    int j = right;
    int temp = array[left];
    while (i < j)
    {
        while (i < j && array[j] >= temp)
        {
            j--;
        }
        array[i] = array[j];
        while (i < j && array[i] < temp)
        {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = temp;
    
    return i;
}

/**
 * array[]: 要排序的数组
 * left: 起始下标
 * right: 结束下标
 * return(int): 返回第 K 大的数
*/
int randSelect(int array[], int left, int right, int K)
{
    // bound
    if (left == right)
    {
        return array[left];
    }
    // pivot 的位置
    int pivot = randPartition(array, left, right);
    // array[pivot] 是 [left, right] 中的第 M 大的数
    int M = pivot - left + 1;
    // 找到了第 K 大的数
    if (K == M)
    {
        return array[pivot];
    }
    // 在左边，则是第 K 大的数
    if (K < M)
    {
        return randSelect(array, left, pivot - 1, K);
    }
    // 在右边，则是第 K - M 大的数
    else 
    {
        return randSelect(array, pivot + 1, right, K - M);
    }
}

int main()
{
    int num;
    cout << "Input the number of the sequence: ";
    cin >> num;
    // dynamic array
    int *array = new int[num];
    // input 
    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }
    int K;
    cout << "Input K: ";
    cin >> K;

    cout << "The Kth largest number is: " << randSelect(array, 0, num - 1, K) << endl;

    return 0;   
}