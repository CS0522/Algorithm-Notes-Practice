/**
 * P466 Stack (30)
 * 分块思想
*/

#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cctype>
// 可能的最大数
#define MAXN 1000010
// block 的个数
#define SQRTN 316

using namespace std;

// 将 string 转换为小写
string str_toLower(string str)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        result += tolower(str[i]);
    }
    return result;
}

// 建立 command 映射
map<string, int> commandMap;
// stack
stack<int> extendStack;
// block 
int block[SQRTN] = {0};
// table
int table[MAXN] = {0};
// total count of the numbers
int totalCount = 0;


// peekMedian
void peekMedian()
{
    // 求第 K 大的数
    int K;
    if (totalCount % 2 == 0)
    {
        K = totalCount / 2;
    }
    else 
    {
        K = (totalCount + 1) / 2;
    }
    if (K == 0)
    {
        K = 1;
    }
    // cout << "totalCount: " << totalCount << endl;
    // cout << "K: " << K << endl;
    // 开始查找 block
    int sum = 0;
    int i;
    for (i = 0; i < SQRTN; i++)
    {
        if (sum + block[i] >= K)
        {
            break;
        }
        sum += block[i];
    }
    // 在第 i 个 block 中，开始查找 table
    int j;
    for (j = i * SQRTN; j < (i + 1) * SQRTN; j++)
    {
        // 找到了
        if (sum + table[j] >= K)
        {
            cout << j << endl;
            return;
        }
        sum += table[j];
    }
}

/* Process the command.
 * 分块思想
 * cmdNum: command 的映射值
 * arg: 可能的参数 (push 的值)
*/
void doFunction(int cmdNum, int arg)
{
    // cout << "cmdNum: " << cmdNum << " arg: " << arg << endl;
    // // push
    if (cmdNum == 0)
    {   
        // 对应的 block 的元素个数 + 1
        block[arg / SQRTN] += 1;
        // table 对应的该元素的个数 + 1
        table[arg] += 1;
        // totalCount += 1
        totalCount += 1;
        extendStack.push(arg);
    }
    // peekmedian
    else if (cmdNum == 1)
    {
        if (extendStack.empty())
        {
            cout << "Invalid. " << endl;
            return;
        }
        // do peekmedian
        peekMedian();
    }
    // pop
    else if (cmdNum == 2)
    {
        if (extendStack.empty())
        {
            cout << "Invalid. " << endl;
            return;
        }
        // delete
        int deleteArg = extendStack.top();
        cout << deleteArg << endl;
        block[deleteArg / SQRTN] -= 1;
        table[deleteArg] -= 1;
        totalCount -= 1;
        extendStack.pop();
    }
}

// initialize
void init()
{
    // push: 0, peekmedian: 1, pop: 2
    commandMap.insert(make_pair(str_toLower("Push"), 0));
    commandMap.insert(make_pair(str_toLower("PeekMedian"), 1));
    commandMap.insert(make_pair(str_toLower("Pop"), 2));

    cout << "Input the number of commands: ";
    int commandNum;
    cin >> commandNum;
    // 接收 commands
    for (int i = 0; i < commandNum; i++)
    {
        // 接收 command, arg
        string cmdtemp;
        int arg = -1;
        cin >> cmdtemp;
        // 如果是 push, 则需要接收一个参数
        if (commandMap[str_toLower(cmdtemp)] == 0)
        {
            cin >> arg;
        }
        // 然后进行 process the command
        doFunction(commandMap[str_toLower(cmdtemp)], arg);
    }
}

int main()
{
    init();
    return 0;
}