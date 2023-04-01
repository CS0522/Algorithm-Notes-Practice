/**
 * P371 Dijkstra 邻接表版
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAXV 10000

using namespace std;

struct Node
{
    // 边指向的节点
    int vertix;
    // 边权 (距离)
    int distance;

    Node() {}
    Node(int _vertix, int _distance): vertix(_vertix), distance(_distance) {}
};

// 顶点个数
int vertixNum;
// Graph
vector<Node> graph[MAXV];
// 起点到某个点的距离 dis[]
int dis[MAXV];
// 是否已经访问过
bool hasVisited[MAXV] = {false};
// 顶点的前驱
int previous[MAXV];

// dijkstra algorithm
void Dijkstra(int start)
{
    // 先将 dis[] 数组填满为 INT_MAX
    fill(dis, dis + MAXV, INT_MAX);
    // 初始化 previous 数组，初始为自身
    for (int i = 0; i < vertixNum; i++)
    {
        previous[i] = i;
    }
    // start 起点自己的值为 0 
    dis[start] = 0;
    // 循环 vertixNum 次
    // 一次可以更新一个 vertix
    for (int i = 0; i < vertixNum; i++)
    {
        int u = -1;
        int minDis = INT_MAX;
        // 找到未访问的 dis 最小的那个顶点 u
        // 也就是找到接下来要访问的顶点
        for (int j = 0; j < vertixNum; j++)
        {
            if (hasVisited[j] == false && dis[j] < minDis)
            {
                // 转移当前要访问的顶点
                u = j;
                minDis = dis[j];
            }
        }
        // 如果没有找到距离更小的，return
        if (u == -1 || minDis == INT_MAX)
        {
            return;
        }
        // 更新距离
        // 与 u 邻接的顶点
        for (int m = 0; m < graph[u].size(); m++)
        {
            // 获取某一条边指向的顶点
            int v = graph[u][m].vertix;
            // 没有访问过 && 距离比当前 dis[] 更小
            if (hasVisited[v] == false && (dis[u] + graph[u][m].distance < dis[v]))
            {
                dis[v] = dis[u] + graph[u][m].distance;
                previous[v] = u;
            }
        }
    }
}

void printPath(int start, int previousIndex)
{
    if (previousIndex == start)
    {
        cout << "Start: " << endl;
        cout << start << endl;
        return;
    }
    printPath(start, previous[previousIndex]);
    cout << previousIndex << endl;
}