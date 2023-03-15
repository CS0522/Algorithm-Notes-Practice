/**
 * P142 快速排序 递归
*/
#include <iostream>
using namespace std;

/**
 * array[]: 要进行分割的数组
 * left: 起始下标
 * right: 结束下标
 * return: pivot 的下标
*/
int partition(int array[], int left, int right)
{
    // 将 pivot 的值临时存储
    // 设定 pivot 为左边第一个
    int pivotValue = array[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        // 先从离 pivot 较远端开始
        while (i < j && array[j] >= pivotValue)
        {
            j--;
        }
        // 不满足条件2时
        array[i] = array[j];
        while (i < j && array[i] <= pivotValue)
        {
            i++;
        }
        array[j] = array[i];
    }
    // 跳出循环，此时 i == j，也就是 pivot 应该呆在的位置
    array[i] = pivotValue;

    return i;
}

/**
 * array[]: 要排序的数组
 * left: 起始下标
 * right: 结束下标
*/
void quickSortFunc(int array[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(array, left, right);
        // 左子区间
        quickSortFunc(array, left, pivot);
        // 右子区间
        quickSortFunc(array, pivot + 1, right);
    }
}

int main()
{
    int array[] = {35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55};
    quickSortFunc(array, 0, sizeof(array) / sizeof(int) - 1);
    // print
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}