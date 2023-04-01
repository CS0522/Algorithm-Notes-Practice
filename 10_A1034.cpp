/**
 * P354 Head of a Gang
 * 图的 DFS 遍历
*/

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

#define MAXN 1010

using namespace std;

// 用来建立 名字 和 编号 的映射关系
map<string, int> name2num;
map<int, string> num2name;

// 记录 Gang 的数据
// string: head 名字，int: gang 的总人数
map<string, int> gang;

// 记录一个点的权值
map<int, int> vertixWeight;
// 图 邻接矩阵
// 首先初始化为 无穷，无法达到
int graph[MAXN][MAXN] = {INT_MAX};
// 判断是否访问过
int hasVisited[MAXN] = {false};

/**DFS 遍历一个连通块
 * current: 当前访问的顶点
 * &head: 该连通块点权最大的顶点
 * &totalTimeLength: 总边权
 * &totalNum: 该连通块的总人数
*/
void DFS(int current, int &head, int &totalTimeLength, int &totalNum)
{
    // 访问当前的顶点
    totalNum += 1;
    // set true
    hasVisited[current] = true;
    // 是否需要更新 head
    if (vertixWeight[current] > vertixWeight[head])
    {
        head = current;
    }
    // 遍历 current 的邻接点
    for (int i = 0; i < vertixWeight.size(); i++)
    {
        // 邻接点
        // 对称矩阵，不需要遍历已经遍历过的
        if (graph[current][i] < INT_MAX && i > current)
        {   
            totalTimeLength += graph[current][i];
            // 如果没有访问过
            if (!hasVisited[i])
            {
                DFS(i, head, totalTimeLength, totalNum);
            }
        }
    }
}

/**DFS 遍历连通块
 * count: 全体人数
 * k: 判断是 Gang 的阈值
*/
void DFSTraverse(int count, int k)
{
    for (int i = 0; i < count; i++)
    {
        // 如果没有访问过
        if (hasVisited[i] == false)
        {
            // 说明是一个新的连通块
            int head = i, totalTimeLength = 0, totalNum = 0;
            DFS(i, head, totalTimeLength, totalNum);
            // 访问完了，通过引用带回了数据
            // 判断是否是 Gang
            if (totalTimeLength > k && totalNum > count)
            {
                gang.insert(make_pair(num2name[head], totalNum));
            }
        }
    }
}

// 初始化数据
void init()
{
    // num: phone calls number
    // k: threthold
    int num, k;
    int count = 0;
    cout << "Input the number of calls and the threthold: ";
    cin >> num >> k;
    cout << "Input the relations: " << endl;
    for (int i = 0; i < num; i++)
    {
        string name1, name2;
        int timeLength;
        cin >> name1 >> name2 >> timeLength;
        // 判断是否需要添加新的映射
        if (name2num.find(name1) == name2num.end())
        {
            name2num.insert(make_pair(name1, count));
            num2name.insert(make_pair(count, name1));
            vertixWeight.insert(make_pair(count, 0));
            count += 1;
        }
        if (name2num.find(name2) == name2num.end())
        {
            name2num.insert(make_pair(name2, count));
            num2name.insert(make_pair(count, name2));
            vertixWeight.insert(make_pair(count, 0));
            count += 1;
        }
        // 加点权
        vertixWeight[name2num[name1]] += timeLength;
        vertixWeight[name2num[name2]] += timeLength;
        // 加边权
        // 如果刚开始这两个点不是邻接的，那么先设置为 0
        if (graph[name2num[name1]][name2num[name2]] == INT_MAX)
        {
            graph[name2num[name1]][name2num[name2]] = 0;
        }
        if (graph[name2num[name2]][name2num[name1]] == INT_MAX)
        {
            graph[name2num[name2]][name2num[name1]] = 0;
        }
        graph[name2num[name1]][name2num[name2]] += timeLength;
        graph[name2num[name2]][name2num[name1]] += timeLength;
    }
}

// print
void print()
{
    cout << "All Gangs' info: " << endl;
    for (map<string, int>::iterator it = gang.begin(); it != gang.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

// test
void test()
{
    cout << "graph: " << endl;
    for (int i = 0; i < vertixWeight.size(); i++)
    {
        for (int j = 0; j < vertixWeight.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << "name2num: " << endl;
    for (map<string, int>::iterator it = name2num.begin(); it != name2num.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << "num2name: " << endl;
    for (map<int, string>::iterator it = num2name.begin(); it != num2name.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << "vertix weight: " << endl;
    for (map<int, int>::iterator it = vertixWeight.begin(); it != vertixWeight.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    init();
    test();
    return 0;
}