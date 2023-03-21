/**
 * P261 Sharing 链表
*/

#include <iostream>
#include <string>
#define MAXN 100010

using namespace std;

// 静态链表
class Node {
public: 
    int address;
    char letter;
    int next;
    // 记录是否被某个链表扫过
    bool hasChecked;
};

void shareSubfix(Node staticList[], int startAddr1, int startAddr2)
{
    // 第一个链表进行 traversal
    for (int tempAddr = startAddr1; tempAddr != -1; tempAddr = staticList[tempAddr].next)
    {
        // 标记
        staticList[tempAddr].hasChecked = true;
    }
    // 第二个链表进行 traversal
    // if .hasChecked == true, break
    for (int tempAddr = startAddr2; tempAddr != -1; tempAddr = staticList[tempAddr].next)
    {
        if (staticList[tempAddr].hasChecked)
        {
            cout << tempAddr << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}


int main()
{
    // 声明静态链表
    Node staticList[MAXN];
    // input
    int startAddr1;
    int startAddr2;
    int totalNum;
    cout << "Input start address1, start address2, and total number: ";
    cin >> startAddr1 >> startAddr2 >> totalNum;
    cout << "Input info as <addr letter next>: " << endl;
    for (int i = 0; i < totalNum; i++)
    {
        int addr;
        char ltr;
        int next;
        cin >> addr >> ltr >> next;
        staticList[addr].address = addr;
        staticList[addr].letter = ltr;
        staticList[addr].next = next;
        staticList[addr].hasChecked = false;
    }
    // function 
    shareSubfix(staticList, startAddr1, startAddr2);

    return 0;
}