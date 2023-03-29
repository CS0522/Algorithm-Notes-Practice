/**
 * P344 哈夫曼树
 * 优先队列 小根堆
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 小根堆
priority_queue<int, vector<int>, greater<int>> small_heap;

void init()
{
    int num;
    cout << "Input the number of nodes: ";
    cin >> num;
    // 初始化优先队列 小根堆
    for (int i = 0; i < num; i++)
    {
        int newVal;
        cin >> newVal;
        small_heap.push(newVal);
    }
}

int getMinWeightPath()
{
    int result = 0;
    while (small_heap.size() >= 2)
    {
        // 取出最小的两个元素
        int a = small_heap.top();
        small_heap.pop();
        int b = small_heap.top();
        small_heap.pop();
        small_heap.push(a + b);
        result += a + b;
    }

    return result;
}

int main()
{
    init();
    int result = getMinWeightPath();
    cout << "Minimum weight path length is: " << result << endl;
    return 0;
}