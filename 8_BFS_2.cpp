/**
 * P278 BFS 走迷宫
*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class MatrixNode 
{
public:
    // *, ., S, T
    char symbol;
    bool hasVisited = false;
    MatrixNode() {}
    MatrixNode(char _symbol): symbol(_symbol) {}
};

class Node
{
public:
    int x;
    int y;
    // 走的次数 (遍历的层数)
    int step = 0;
    Node() {}
    Node(int _x, int _y): x(_x), y(_y) {}
    Node(int _x, int _y, int _step): x(_x), y(_y), step(_step) {}
};

// matrix
int row, col;
MatrixNode **matrix;
// start node and end node
Node startNode, endNode;
// 增量数组
int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

void print()
{
    // print
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j].symbol << " ";
        }
        cout << endl;
    }
}

void init()
{
    cout << "Input row, col: ";
    cin >> row >> col;
    cout << "Input the matrix, and input the data by row: " << endl;
    // 初始化 matrix
    matrix = new MatrixNode* [row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new MatrixNode[col];
        getchar();
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j].symbol;
        }
    }
    // print
    // print();
    // start node and end node
    cout << "Input start node's coordinate (x, y): ";
    cin >> startNode.x >> startNode.y;
    startNode.x -= 1;
    startNode.y -= 1;
    cout << "Input end node's coordinate (x, y): ";
    cin >> endNode.x >> endNode.y;
    endNode.x -= 1;
    endNode.y -= 1;
}

// 判断是否需要访问
bool isNeedVisit(int x, int y)
{
    // 越界
    if (x >= row || x < 0 || y >= col || y < 0)
    {
        return false;
    }
    // 已经访问过
    if (matrix[x][y].hasVisited == true)
    {
        return false;
    }
    // 是墙壁
    if (matrix[x][y].symbol == '*')
    {
        return false;
    }

    return true;
}


int BFS(int x, int y, int currentStep)
{
    queue<Node> visitNode;
    Node currentNode(x, y, currentStep);
    visitNode.push(currentNode);
    // 设置该 matrixNode 为访问过
    matrix[x][y].hasVisited = true;

    while (!visitNode.empty())
    {
        Node frontNode = visitNode.front();
        visitNode.pop();
        // 发现到达 T
        if (frontNode.x == endNode.x && frontNode.y == endNode.y)
        {
            return frontNode.step;
        }

        for (int i = 0; i < 4; i++)
        {
            int newX = frontNode.x + X[i];
            int newY = frontNode.y + Y[i];
            int newStep = frontNode.step + 1;
            if (isNeedVisit(newX, newY))
            {
                Node newNode(newX, newY, newStep);
                visitNode.push(newNode);
                matrix[newX][newY].hasVisited = true;
            }
        }
    }
    // 队列循环结束，没有达到 T，搜索失败
    return -1;
}

int main()
{
    init();
    int step = BFS(startNode.x, startNode.y, 0);
    cout << (step == -1 ? "Search failed. " : "Total steps: " + to_string(step)) << endl;
    return 0;
}