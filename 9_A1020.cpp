/**
 * P296 树的遍历
 * 由后序遍历和中序遍历，构造二叉树
 * 返回该二叉树的层序遍历
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> postOrder;
vector<int> inOrder;
// vector<int> levelOrder;

struct Node 
{
    // data
    int data;
    Node *lchild;
    Node *rchild;
    int level = 0;

    Node() { this->lchild = nullptr; this->rchild = nullptr; }
    Node(int _data): data(_data) { this->lchild = nullptr; this->rchild = nullptr; }
};

// initialize
void init()
{
    cout << "Input the amount of all nodes: ";
    int n;
    cin >> n;
    cout << "Input the post-order: ";
    for (int i = 0; i < n; i++)
    {
        int newVal;
        cin >> newVal;
        postOrder.push_back(newVal);
    }
    cout << "Input the in-order: ";
    for (int i = 0; i < n; i++)
    {
        int newVal;
        cin >> newVal;
        inOrder.push_back(newVal);
    }
}

/**返回获得的根节点的地址
 * postStart, postEnd: 后序遍历的起始、结束下标
 * inStart, inEnd: 中序遍历的起始、结束下标
*/
Node* create(int postStart, int postEnd, int inStart, int inEnd)
{
    // 边界条件
    if (postStart > postEnd)
    {
        return nullptr;
    }
    // 从后序遍历中获得根节点
    Node *root = new Node(postOrder[postEnd]);
    // 在中序遍历中找到该节点
    int k;
    for (k = inStart; k <= inEnd; k++)
    {
        if (postOrder[postEnd] == inOrder[k])
        {
            break;
        }
    }
    // 左子树节点总数
    // 右子树节点总数
    int numL = k - inStart;
    int numR = inEnd - k;
    // 左子树后序遍历区间 [postStart, postStart + numL -1]
    // 左子树中序遍历区间 [inStart, k - 1]
    root->lchild = create(postStart, postStart + numL -1, inStart, k - 1);
    // 右子树后序遍历区间 [postStart + numL, postEnd - 1]
    // 右子树中序遍历区间 [k + 1, inEnd]
    root->rchild = create(postStart + numL, postEnd - 1, k + 1, inEnd);

    return root;
}

void visit(Node *targetNode)
{
    if (targetNode == nullptr)
    {
        return;
    }
    // 访问
    cout << targetNode->data << "(" << targetNode->level << ")" << " ";
}

/**
 * 层序遍历
*/
void levelTraversal(Node *root)
{
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        // 出队
        Node *topNode = nodeQueue.front();
        nodeQueue.pop();
        // 访问
        // 层序 + 1
        visit(topNode);
        // 子树入队
        if (topNode->lchild != nullptr)
        {
            topNode->lchild->level = topNode->level + 1;
            nodeQueue.push(topNode->lchild);
        }
        if (topNode->rchild != nullptr)
        {
            topNode->rchild->level = topNode->level + 1;
            nodeQueue.push(topNode->rchild);
        }
    }
}

int main()
{
    init();
    // 返回二叉树
    Node *tree = create(0, postOrder.size() - 1, 0, inOrder.size() - 1);
    levelTraversal(tree);
    cout << endl;

    return 0;
}