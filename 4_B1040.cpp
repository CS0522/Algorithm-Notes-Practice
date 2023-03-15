/**
 * P147 有几个 PAT
 * 思路：不能暴力求解。对于一个确定位置的 A，num("PAT") = num("左边的 P") * num("右边的 T")
*/

#include <iostream>
#include <cstring>
using namespace std;

/**
 * sampleStr: 给定的字符串
 * *leftPNum: 一个用于记录每一位左边有几个'P'的数组
*/
int calPAT(string &sampleStr, int leftPNum[])
{
    // 计算 leftPNum[] 数组
    for (int i = 0; i < sampleStr.length(); i++)
    {
        if (i == 0)
        {
            if (sampleStr[i] == 'P')
            {
                leftPNum[i] = 1;
            }
            else
            {
                leftPNum[i] = 0;
            }
        }
        else
        {
            if (sampleStr[i] == 'P')
            {
                leftPNum[i] = leftPNum[i - 1] + 1;
            }
            else
            {
                leftPNum[i] = leftPNum[i - 1];
            }
        } 
    }
    // 查找'A'的位置。逆向计算右边的'T'的个数，找到一个'A'，计算'PAT'的个数
    int result = 0;
    int rightTNum = 0;
    for (int j = sampleStr.length(); j > 0 ; j--)
    {
        if (sampleStr[j] == 'T')
        {
            rightTNum += 1;
        }
        // find 'A'
        if (sampleStr[j] == 'A')
        {
            result += leftPNum[j] * rightTNum;
        }
    }

    return result;
}

int main()
{
    // 给定的字符串
    string sampleStr;
    cout << "Input a string: ";
    cin >> sampleStr;

    if (sampleStr.length())
    {
        // 一个数组，用于计算字符串的每一位的左边有几个'P'
        int *leftPNum = new int[sampleStr.length()];
        cout << "Amount of \'PAT\': " << calPAT(sampleStr, leftPNum) << endl;
    }

    return 0;
}