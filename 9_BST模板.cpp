struct Node 
{
    int data;
    Node *lchild;
    Node *rchild;

    Node() { this->lchild = nullptr; this->rchild = nullptr; }
    Node(int _data): data(_data) { this->lchild = nullptr; this->rchild = nullptr; }
};

Node* findMax(Node *root)
{
    while (root->rchild != nullptr)
    {
        root = root->rchild;
    }

    return root;
}

Node* findMin(Node *root)
{
    while (root->lchild != nullptr)
    {
        root = root->lchild;
    }

    return root;
}

// 插入节点
void ins(Node *&root, int x)
{
    // 查找失败，也就是要插入的位置
    if (root == nullptr)
    {
        root = new Node(x);
        return;
    }
    if (root->data < x)
    {
        ins(root->rchild, x);
    }
    else if (root->data > x)
    {
        ins(root->lchild, x);
    }
    else
    {
        return;
    }
}

// 删除节点
void del(Node *&root, int x)
{
    // 没有找到要删除的节点
    if (root == nullptr)
    {
        return;
    }
    // 找到这个要删除的节点
    if (root->data == x)
    {
        // 无左右子树，叶子节点，直接删除
        if (root->lchild == nullptr && root->rchild == nullptr)
        {
            delete root;
            // 避免野指针
            root = nullptr;
        }
        // 有左，查找左子树中的最大值，替换，递归
        else if (root->lchild != nullptr)
        {
            Node *preNode = findMax(root->lchild);
            root->data = preNode->data;
            del(root->lchild, preNode->data);
        }
        // 有右无左，查找右子树中的最小值，替换，递归
        else if (root->rchild != nullptr)
        {
            Node *nextNode = findMin(root->rchild);
            root->data = nextNode->data;
            del(root->rchild, nextNode->data);
        }
    }
    // 向右子树递归
    else if (root->data < x)
    {
        del(root->rchild, x);
    }
    // 向左子树递归
    else if (root->data > x)
    {
        del(root->lchild, x);
    }
}