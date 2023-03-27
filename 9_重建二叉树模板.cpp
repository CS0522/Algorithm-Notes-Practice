#define MAXN 10

struct Node 
{
    int data;
    Node *lchild;
    Node *rchild;
    Node() { this->lchild = nullptr; this->rchild = nullptr; }
    Node(int _data): data(_data) { this->lchild = nullptr; this->rchild = nullptr; }
};

int preOrder[MAXN];
int inOrder[MAXN];

/**返回获得的根节点的地址
 * preStart, preEnd: 先序遍历的起始、结束下标
 * inStart, inEnd: 中序遍历的起始、结束下标
*/
Node *create(int preStart, int preEnd, int inStart, int inEnd)
{
    // 当传入的先序遍历的长度 <= 0，返回
    if (preStart >= preEnd)
    {
        return nullptr;
    }
    // 先序遍历的第一个节点即为根节点
    Node *root = new Node(preOrder[preStart]);
    // 在中序遍历中查找这个根节点
    int k;
    for (k = inStart; k <= inEnd; k++)
    {
        if (inOrder[k] == preOrder[preStart])
        {
            break;
        }
    }
    // 左子树节点数
    int numL = k - inStart;
    // 右子树节点数
    int numR = inEnd -k;
    // 计算
    // 左子树的先序遍历区间 [preStart + 1, preStart + 1 + numL - 1]
    // 左子树的中序遍历区间 [inStart, k - 1]
    root->lchild = create(preStart + 1, preStart + numL, inStart, k - 1);
    // 右子树的先序遍历区间 [preStart + 1 + numL - 1 + 1, preEnd]
    // 右子树的中序遍历区间 [k + 1, inEnd]
    root->rchild = create(preStart + numL + 1, preEnd, k + 1, inEnd);

    return root;
}