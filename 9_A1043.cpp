/**
 * P315 Is it a BST
 * 根据输入序列，构建一个BST
 * 输出先序遍历和镜像先序遍历，进行比对
 * 输出后序遍历
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node 
{
    int data;
    Node *lchild;
    Node *rchild;

    Node() { this->lchild = nullptr; this->rchild = nullptr; }
    Node(int _data): data(_data) { this->lchild = nullptr; this->rchild = nullptr; }
};

vector<int> inputSq;
vector<int> preOrderSq;
vector<int> mirrorPreOrderSq;
vector<int> postOrderSq;
vector<int> mirrorPostOrderSq;

Node *tree = nullptr;

// 插入节点
void insert(Node* &root, int x)
{
    // 查找失败，也就是插入的位置
    if (root == nullptr)
    {
        root = new Node(x);
        return;
    }
    if (root->data <= x)
    {
        insert(root->rchild, x);
    }
    else if (root->data > x)
    {
        insert(root->lchild, x);
    }
}

void init()
{
    cout << "Input the amounts of node: ";
    int num;
    cin >> num;
    cout << "Input the sequence: " << endl;
    for (int i = 0; i < num; i++)
    {
        int newData;
        cin >> newData;
        inputSq.push_back(newData);
    }
    // 构造二叉树
    for (int i = 0; i < inputSq.size(); i++)
    {
        insert(tree, inputSq[i]);
    }
}

// 将某个节点输出到对应的 vector 中
void visit(Node *&targetNode, vector<int> &orderSq)
{
    orderSq.push_back(targetNode->data);
}

// 输出到 preOrderSq 序列中
void preOrder(Node* &root)
{
    if (root == nullptr)
    {
        return;
    }
    visit(root, preOrderSq);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

// 输出到 mirrorPreOrderSq 序列中
void mirrorPreOrder(Node* &root)
{
    if (root == nullptr)
    {
        return;
    }
    visit(root, mirrorPreOrderSq);
    mirrorPreOrder(root->rchild);
    mirrorPreOrder(root->lchild);
}

// postOrder
void postOrder(Node* &root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    visit(root, postOrderSq);
}

// mirrorPostOrder
void mirrorPostOrder(Node* &root)
{
    if (root == nullptr)
    {
        return;
    }
    mirrorPostOrder(root->rchild);
    mirrorPostOrder(root->lchild);
    visit(root, mirrorPostOrderSq);
}

// 对比 inputSq, preOrderSq, and mirrorPreOrderSq
/*
* vector 默认重载了 == operator
*/
bool compare(vector<int> &targetSq, vector<int> &cmpSq)
{
    for (int i = 0; i < targetSq.size(); i++)
    {
        if (targetSq[i] != cmpSq[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    init();
    preOrder(tree);
    mirrorPreOrder(tree);
    // 对比 inputSq, preOrderSq, and mirrorPreOrderSq
    if (inputSq == preOrderSq)
    {
        cout << "YES. " << endl;
        // 输出 postOrderSq
        postOrder(tree);
        for (int i = 0; i < postOrderSq.size(); i++)
        {
            cout << postOrderSq[i] << " ";
        }
        cout << endl;
    }
    else if (inputSq == mirrorPreOrderSq)
    {
        cout << "YES. " << endl;
        // 输出 mirrorPostOrderSq
        mirrorPostOrder(tree);
        for (int i = 0; i < mirrorPostOrderSq.size(); i++)
        {
            cout << mirrorPostOrderSq[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO. " << endl;
    }
    return 0;
}