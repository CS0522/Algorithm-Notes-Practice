/**
 * P141 归并排序
*/

#include <iostream>
using namespace std;

/**
 * array[]: 要进行合并的数组
 * A_left: 左子区间起始下标
 * A_right: 左子区间结束下标
 * B_left: 右子区间起始下标
 * B_right: 右子区间结束下标
*/
void merge(int array[], int A_left, int A_right, int B_left, int B_right)
{
    // 存放临时数组
    int *tempArray = new int[(B_right + A_right - B_left - A_left + 2) + 1];
    int i = A_left;
    int j = B_left;
    int index = 0;

    // 从小到大进行排序
    while (i <= A_right && j <= B_right)
    {
        if (array[i] <= array[j])
        {
            tempArray[index++] = array[i++];
        }
        else
        {
            tempArray[index++] = array[j++];
        }
    }
    // 跳出 while 循环，可能有某个子区间没有全部加入到临时数组中
    while (i <= A_right)
    {
        tempArray[index++] = array[i++];
    }
    while (j <= B_right)
    {
        tempArray[index++] = array[j++];
    }
    // array中的被赋值
    for (int k = 0; k < index; k++)
    {
        array[A_left + k] = tempArray[k];
    }
}

/**
 * array[]: 要排序的数组
 * left: 排序区间的起始下标
 * right: 排序区间的结束下标
*/
void mergeSortFunc(int array[], int left, int right)
{
    if (left < right)
    {
        mergeSortFunc(array, left, (left + right) / 2);
        mergeSortFunc(array, (left + right) / 2 + 1, right);
        // 左右子区间进行归并
        merge(array, left, (left + right) / 2, (left + right) / 2 + 1, right);
    }
}

int main()
{
    // 要进行归并排序的数组
    int array[] = {66, 12, 33, 64, 57, 27, 18};
    mergeSortFunc(array, 0, sizeof(array) / sizeof(int));
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}