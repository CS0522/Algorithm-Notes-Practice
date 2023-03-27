#include <iostream>
#include <cstdlib>
using namespace std;

struct Node 
{
    int data;
    int height = 1;
    Node *lchild;
    Node *rchild;

    Node() { this->lchild = nullptr; this->rchild = nullptr; }
    Node(int _data): data(_data) { this->lchild = nullptr; this->rchild = nullptr; }
};

// 计算平衡因子 Balance Factor
int calBF(Node *&root)
{
    return (root->lchild->height - root->rchild->height);
}

// 更新节点的 height
void updateHeight(Node *&root)
{
    root->height = (max(root->lchild->height, root->rchild->height) + 1);
}

// 查找节点 (略)

// 左旋，右旋
void leftRotation(Node *&root)
{
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    // 千万别忘了更新节点高度
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rightRotation(Node *&root)
{
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}


// 插入节点，在二叉查找树的基础上，还要确保平衡
// weight: 插入权值
void insert(Node* &root, int weight)
{
    if (root == nullptr)
    {
        root = new Node(weight);
        return;
    }
    // to left child
    if (root->data > weight)
    {
        // 先插入，这里有递归
        // 所以相当于从插入节点开始，从下往上执行AVL的 保持平衡 的操作
        insert(root->lchild, weight);
        // 保持平衡
        updateHeight(root);
        // 判断 LL、LR
        if (calBF(root) == 2)
        {
            // LL
            if (calBF(root->lchild) == 1)
            {
                // 右旋
                rightRotation(root);
            }
            // LR
            else if (calBF(root->lchild) == -1)
            {
                // 先对 root->lchild 左旋，再对 root 右旋
                leftRotation(root->lchild);
                rightRotation(root);
            }
        }
    }
    // to right child
    if (root->data < weight)
    {
        insert(root->rchild, weight);
        updateHeight(root);
        // 判断 RR、RL
        if (calBF(root) == 2)
        {
            // RR
            if (calBF(root->rchild) == -1)
            {
                // 左旋
                leftRotation(root);
            }
            // RL
            else if (calBF(root->rchild) == 1)
            {
                // 先对 root->rchild 右旋，再对 root 左旋
                rightRotation(root->rchild);
                leftRotation(root);
            }
        }
    }
}