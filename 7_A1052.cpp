/**
 * P265 Linked List Sorting
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#define MAXN 100010

using namespace std;

class Node 
{
public:
    int address;
    int data;
    int next;
    // 节点是否在链表上
    bool flag = false;

    Node() {}
};

/**
 * 返回有效节点数
*/
int listTraverse(Node staticList[], int startAddr)
{
    int nodeCount = 0;
    for (int i = startAddr; i != -1; i = staticList[i].next)
    {
        staticList[i].flag = true;
        nodeCount += 1;
    }

    return nodeCount;
}

// 比较函数
// 如果 flag == true，说明是链表中的节点，根据 data 从小到大排序
// 如果 flag == false，说明不是链表中的节点，往数组后面放，也就是按 flag 从大到小排序
bool cmp(Node a, Node b)
{
    if (a.flag == true && b.flag == true)
    {
        return a.data < b.data;
    }
    else
    {
        return a.flag > b.flag;
    }
}

void listSort(Node staticList[], int startAddr, int nodeCount)
{
    // 进行排序
    // 效果：flag 为 true(1) 的在 staticList 的左端，且按照 data 从小到大进行排序
    sort(staticList, staticList + MAXN, cmp);
    // traverse and update the new 'next'
    for (int i = 0; i < nodeCount; i++)
    {
        staticList[i].next = staticList[i].address;
        // 最后一个有效节点
        if (i == nodeCount - 1)
        {
            staticList[i].next = -1;
        }
    }
}

void print(Node staticList[], int nodeCount)
{
    cout << "After having sorted the list: " << endl;
    cout << "Node count: " << nodeCount << endl;
    for (int i = 0; i < nodeCount; i++)
    {
        cout << "<" << setw(5) << setfill('0') << staticList[i].address << ", "; 
        cout << staticList[i].data << ", ";
        if (staticList[i].next == -1)
        {
            cout << -1 << ">" << endl;
            return;
        }
        cout << setw(5) << setfill('0') << staticList[i].next << ">" << endl;
    }
}

int main()
{
    // 声明静态链表
    Node staticList[MAXN];
    // input
    int startAddr;
    int totalNum;
    cout << "Input total number and start address: ";
    cin >> totalNum >> startAddr;
    cout << "Input info as <addr letter next>: " << endl;
    for (int i = 0; i < totalNum; i++)
    {
        int addr;
        int data;
        int next;
        cin >> addr >> data >> next;
        staticList[addr].address = addr;
        staticList[addr].data = data;
        staticList[addr].next = next;
        staticList[addr].flag = false;
    }
    // traverse
    int nodeCount = listTraverse(staticList, startAddr);
    // sort
    listSort(staticList, startAddr, nodeCount);
    // print
    print(staticList, nodeCount);
    return 0;
}