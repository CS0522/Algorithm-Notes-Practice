#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heap;

// 从上而下进行调整
/**
 * low: 要调整的下标
 * high: 结束下标
*/
void downAdjust(int low, int high)
{
    // 双指针
    // 当前节点，当前节点的左孩子
    int i = low, j = i * 2;
    while (j <= high)
    {
        if (j + 1 <= high && heap[j + 1] > heap[j])
        {
            // 指向右孩子
            j = j + 1;
        }
        if (heap[i] < heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
}

// 建堆操作
void createHeap()
{
    for (int i = (heap.size() - 1) / 2; i >= 1; i--)
    {
        downAdjust(i, heap.size() - 1);
    }
}

// delete operation
void deleteTop()
{
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    downAdjust(1, heap.size() - 1);
}

// 从下而上进行调整
/**
 * low: 结束下标 (一般为 1)
 * high: 要调整的下标
*/
void upAdjust(int low, int high)
{
    int i = high, j = i / 2;
    while (j >= low)
    {
        if (heap[i] > heap[j])
        {
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }
        else
        {
            break;
        }
    }
}

// add operation
void insert(int x)
{
    heap.push_back(x);
    upAdjust(1, heap.size() - 1);
}


// 堆排序
void heapSort()
{
    createHeap();
    for (int i = heap.size() - 1; i > 1; i++)
    {
        swap(heap[i], heap[1]);
        downAdjust(1, i - 1);
    }
}