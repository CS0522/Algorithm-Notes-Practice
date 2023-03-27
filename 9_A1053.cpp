/**
 * P305 Path of Equal Weights
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node 
{
    // 节点编号
    int id;
    // 节点权值
    int weight;
    // children，存数组下标
    // 读入 children 的下标后，可以进行从大到小排序，权值更大的子结点优先访问
    vector<int> children;

    Node() {}
    Node(int _weight): weight(_weight) {}
    Node(int _id, int _weight): id(_id), weight(_weight) {}
};

// 树的节点数组
vector<Node> treeNodes;

// 比较函数，按权值从大到小排序
bool cmp(int a, int b)
{
    return treeNodes[a].weight > treeNodes[b].weight;
}

// 访问 weightTotal
int init()
{
    cout << "Input node amounts, non-leaf node amounts, and weight number: ";
    int nodeNum, nonLeafNodeNum, weightTotal;
    cin >> nodeNum >> nonLeafNodeNum >> weightTotal;
    if (nonLeafNodeNum >= nodeNum)
    {
        cout << "non leaf node number is greater than total node number!" << endl;
        return -1;
    }
    cout << "Input the weight of each node (from 00 ~ n): " << endl;
    for (int i = 0; i < nodeNum; i++)
    {
        int weight;
        cin >> weight;
        Node newNode(i, weight);
        treeNodes.push_back(newNode);
    }
    cout << "Input the non-leaf node's id, child amounts, and his child's id: " << endl;
    for (int i = 0; i < nonLeafNodeNum; i++)
    {
        int nonLeafNodeId;
        int childrenNum;
        int childrenId;
        cin >> nonLeafNodeId;
        cin >> childrenNum;
        for (int j = 0; j < childrenNum; j++)
        {
            cin >> childrenId;
            treeNodes[nonLeafNodeId].children.push_back(childrenId);
        }
        // 读入 children 的下标后，可以进行从大到小排序，权值更大的子结点优先访问
        sort(treeNodes[nonLeafNodeId].children.begin(), treeNodes[nonLeafNodeId].children.end(), cmp);
    }

    return weightTotal;
}

void testInit()
{
    for (vector<Node>::iterator it = treeNodes.begin(); it != treeNodes.end(); it++)
    {
        printf("id: %02d, weight: %d \n", it->id, it->weight);
    }
}

// print path
void print(vector<Node> &path)
{
    for (vector<Node>::iterator it = path.begin(); it != path.end(); it++)
    {
        if (it == path.end() - 1)
        {
            cout << it-> weight << endl;
            break;
        }
        cout << it-> weight << " ";
    }
}

/**递归访问这个树
 * index: 正在访问的这个节点的下标
 * pathNodeNum: 当前路径上的节点数
 * sum: 当前路径上的权值的总和
 * weightTotal: 需要达到的权值和
*/
void DFS(int index, int pathNodeNum, int sum, int weightTotal, vector<Node> &path)
{
    int currentSum = sum + treeNodes[index].weight;
    // 加上这个节点后，权值大于目标值，return
    if ( currentSum > weightTotal)
    {
        return;
    }
    else if (currentSum == weightTotal)
    {
        // 如果是叶子节点，将该节点加入path，输出路径
        if (treeNodes[index].children.empty())
        {
            path.push_back(treeNodes[index]);
            print(path);
            path.pop_back();
        }
        // 如果不是叶子节点，return
        else
        {
            return;
        }
    }
    else if (currentSum < weightTotal)
    {
        // 将自己加入 path 中，然后递归访问每个子结点
        path.push_back(treeNodes[index]);
        for (int i = 0; i < treeNodes[index].children.size(); i++)
        {
            DFS(treeNodes[index].children[i], path.size(), currentSum, weightTotal, path);
        }
        // 结束后，将自己从 path 中弹出
        path.pop_back();
    }
}

int main()
{
    int weightTotal = init();
    // testInit();
    vector<Node> path;
    DFS(0, 0, 0, weightTotal, path);

    return 0;
}