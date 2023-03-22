/**
 * P276 BFS 01矩阵
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    // 坐标
    int x;
    int y;
    Node() {}
    Node(int _x, int _y) : x(_x), y(_y) {}
};

// 矩阵大小
int row, col;
int **matrix = new int* [row];
bool **inQueue = new bool* [row];
// 增量矩阵
// 竖着看 (x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

void init()
{
    cout << "Input the size of matrix(row, col): ";
    cin >> row >> col;
    cout << "Input the 0-1 matrix: " << endl;
    // 初始化动态二维数组 (矩阵)
    // 初始化判断数组 (矩阵)
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
        inQueue[i] = new bool[col];
        for (int j = 0; j < col; j++)
        {
            inQueue[i][j] = false;
        }
    }
}

/** 判断是否需要访问 (x, y)
 * x, y: 要判断的点
 * row, col: 边界
*/
bool isNeedVisit(int x, int y)
{
    // 越界
    if (x < 0 || y < 0 || x >= row || y >= col)
    {
        return false;
    }
    // 已经访问过
    if (inQueue[x][y] == true)
    {
        return false;
    }
    // matrix[x][y] == 0
    if (matrix[x][y] == 0)
    {
        return false;
    }

    return true;
}

/** 访问值为 1 的元素，将 inQueue 设置为 true，入队，访问他的邻接
 * X[], Y[]: 增量矩阵
*/
void BFS(int x, int y)
{
    queue<Node> visitQueue;
    Node currentNode(x, y);
    visitQueue.push(currentNode);
    inQueue[x][y] = true;
    
    while (!visitQueue.empty())
    {
        Node topNode = visitQueue.front();
        visitQueue.pop();
        // 增量矩阵，判断相邻的 4 个位置
        for (int i = 0; i < 4; i++)
        {
            int newX = topNode.x + X[i];
            int newY = topNode.y + Y[i];
            if (isNeedVisit(newX, newY) == true)
            {
                Node newNode(newX, newY);
                visitQueue.push(newNode);
                inQueue[newX][newY] = true;
            }
        }
    }
}

int main()
{
    init();
    int blockCount = 0;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1 && inQueue[i][j] == false)
            {
                BFS(i, j);
                blockCount += 1;
            }
        }
    }
    cout << "There is(are) " << blockCount << " block(s). " << endl;

    return 0;
}