/**
 * P455 KMP 算法
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 主串
string text;
// 模式串
string pattern;
// next array
int *nextArray;

void init()
{
    cout << "Input the text string: ";
    cin >> text;
    cout << "Input the pattern string: ";
    cin >> pattern;
    // initialize next array
    nextArray = new int[pattern.length()];
}

// 计算 next 数组
void calNext()
{
    // pointer of pattern string
    int j = -1;
    // nextArray[0] = -1
    nextArray[0] = -1;
    // 计算 nextArray[1] ~ nextArray[length - 1]
    for (int i = 1; i < pattern.length(); i++)
    {
        // 当前 pattern[i] != pattern[j + 1]
        // j pointer 不断回溯 j == nextArray[j]
        // 其实也就是 j pointer 回溯到上一个以相同字母开头的前缀的下标
        while (j != -1 && pattern[i] != pattern[j + 1])
        {
            j = nextArray[j];
        }
        // 跳出循环
        // 当前 pattern[i] == pattern[j + 1]
        if (pattern[i] == pattern[j + 1])
        {
            j += 1;
        }
        // 赋值
        nextArray[i] = j;
    }
}

// KMP
bool KMP()
{
    int j = -1;
    // 开始匹配
    for (int i = 0; i < text.length(); i++)
    {
        while (j != -1 && text[i] != pattern[j + 1])
        {
            j = nextArray[j];
        }
        if (text[i] == pattern[j + 1])
        {
            j++;
        }
        // succeeded
        if (j == pattern.length() - 1)
        {
            return true;
        }
    }
    // failed
    return false;
}

// KMP + pattern出现次数
int calKMPCount()
{
    int result = 0;
    int j = -1;
    for (int i = 0; i < text.length(); i++)
    {
        while (j != -1 && text[i] != pattern[j + 1])
        {
            j = nextArray[j];
        }
        if (text[i] == pattern[j + 1])
        {
            j++;
        }
        // succeeded
        if (j == pattern.length() - 1)
        {
            result += 1;
            // j pointer 回溯
            j = nextArray[j];
        }
    }

    return result;
}

// print
void printNext()
{
    cout << "Next array: " << endl;
    for (int i = 0; i < pattern.length(); i++)
    {
        cout << nextArray[i] << " ";
    }
    cout << endl;
}

int main()
{
    init();
    calNext();
    printNext();
    /*
    if (KMP())
    {
        cout << "Match succeeded. " << endl;
    }
    else
    {
        cout << "Match failed. " << endl;
    }
    */
    int count = calKMPCount();
    if (count != 0)
    {
        cout << "Match succeeded. \nTotal appears " <<  count << " times. " << endl;
    }
    else
    {
        cout << "Match failed. " << endl;
    }
    return 0;
}