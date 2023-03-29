/**
 * P332 好朋友
 * 并查集
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node 
{
    // 该节点的 father 节点
    // 如果自己是根，那么 father 的值就是自己的下标
    int father = -1;
    // 判断是否是某个集合的 root 节点
    bool isRoot = false;

    Node() {}
    Node(int _father, bool _isRoot): father(_father), isRoot(_isRoot) {}
};

// 节点集合
vector<Node> nodeSets;

// 查找
// 这里，一直卡着，没有注意用了引用
// 这里不能用引用
int findRoot(int a)
{
    while (a != nodeSets[a].father)
    {
        a = nodeSets[a].father;
    }
    
    return a;
}

// 合并
void unionSet(int a, int b)
{
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if (rootA != rootB)
    {
        nodeSets[rootB].father = rootA;
        // nodeSets[rootB].isRoot = false;
        // nodeSets[rootA].isRoot = true;
    }
}

void init()
{
    cout << "Input the amount of nodes and the number of pairs: ";
    int num, pairNum;
    cin >> num >> pairNum;
    // init vector
    for (int i = 0; i < num + 1; i++)
    {
        Node newEmptyNode;
        newEmptyNode.father = i;
        nodeSets.push_back(newEmptyNode);
    }
    // combine
    for (int i = 0; i < pairNum; i++)
    {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    // set flag
    for (int i = 1; i < nodeSets.size(); i++)
    {
        nodeSets[findRoot(i)].isRoot = true;
    }
}

int main()
{
    init();
    // print result
    int result = 0;
    for (int i = 1; i < nodeSets.size(); i++)
    {
        if (nodeSets[i].isRoot == true)
        {
            result += 1;
        }
        // cout << nodeSets[i].isRoot << " " << nodeSets[i].father << endl;
    }
    cout << "Set amount: " << result << endl;
    return 0;
}