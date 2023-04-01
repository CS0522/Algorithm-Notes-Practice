/**
 * P363 Forwards on Weibo
 * BFS 遍历
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// direct graph
// 二维动态数组
int **graph;

struct Node
{
    int id;
    int layer;

    Node() {}
    Node(int _id, int _layer): id(_id), layer(_layer) {};
};

// init
void init(int &userNum)
{
    // init direct graph
    graph = new int*[userNum + 1];

    for (int i = 0; i <= userNum; i++)
    {
        graph[i] = new int[userNum + 1];
        // 初始化，先全部设为 0
        for (int j = 0; j <= userNum; j++)
        {
            graph[i][j] = 0;
        }
    }
    // 输入
    for (int i = 1; i <= userNum; i++)
    {
        // 该用户关注的用户数
        int followingNum;
        cin >> followingNum;
        for (int j = 0; j < followingNum; j++)
        {
            // 有向边，由被关注 user 指向关注 user
            int temp;
            cin >> temp;
            graph[temp][i] = 1;
        }
    }
}

// test init
void testInit(int userNum)
{
    cout << "test the input graph: " << endl;
    for (int i = 1; i <= userNum; i++)
    {
        for (int j = 1; j <= userNum; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS
int BFS(int startUser, int &userNum, int &L)
{
    // 记录是否被访问
    bool *hasVisited = new bool[userNum + 1];
    for (int i = 0; i <= userNum; i++)
    {
        hasVisited[i] = false;
    }

    queue<Node> graphQueue;
    int forwardCount = 0;
    // 设为已经访问
    hasVisited[startUser] = true;
    graphQueue.push(Node(startUser, 0));
    while (!graphQueue.empty())
    {
        // 取队首并出队
        Node topNode = graphQueue.front();
        graphQueue.pop();
        if (topNode.layer >= L)
        {
            break;
        }
        // 枚举所有邻接点
        for (int i = 1; i <= userNum; i++)
        {
            if (graph[topNode.id][i] == 1 && hasVisited[i] == false)
            {
                // 人数++
                forwardCount += 1;
                // 入队
                hasVisited[i] = true;
                graphQueue.push(Node(i, topNode.layer + 1));
            }
        }
    }
    // 退出 while，队列空或者达到 level 限制
    return forwardCount;
}

void BFSTraverse(int &userNum, int &L)
{
    vector<int> result;
    cout << "Input the number of query users, and their ID: " << endl;
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int queryUser;
        cin >> queryUser;
        result.push_back(BFS(queryUser, userNum, L));
    }
    // print result
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    // 用户数量
    // 限制转发层级
    int userNum, L;
    cout << "Input the number of users and L level: ";
    cin >> userNum >> L;
    init(userNum);
    // testInit(userNum);
    BFSTraverse(userNum, L);
    return 0;
}