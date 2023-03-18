/**
 * P209 Are They Equal string 字符串
*/

#include <iostream>
#include <string>
using namespace std;

class Notation 
{
private:
    // 本体
    string base;
    // 指数
    int index;
public:
    Notation() {}
    Notation(string base, int index)
    {
        this->base = base;
        this->index = index;
    }
    void setBase(string base)
    {
        this->base = base;
    }
    void setIndex(int index)
    {
        this->index = index;
    }
    string getBase()
    {
        return this->base;
    }
    int getIndex()
    {
        return this->index;
    }
    // 重载操作符
    inline bool operator==(Notation &num2)
    {
        if (this->base == "000" && num2.base == "000")
        {
            return true;
        }
        if (this->index == num2.index && this->base == num2.base)
        {
            return true;
        }
        return false;
    }
};

Notation turnToNotation(string num1, int n)
{
    // 记录指数
    int count = 0;
    // notation num
    Notation notationNum;
    // 1. 去除高位 0
    while (*num1.begin() == '0')
    {
        num1.erase(num1.begin());
    }
    // 2. 去除小数点
    // 2.1 如果第一位小数点，说明没有整数部分
    if (*num1.begin() == '.')
    {
        num1.erase(num1.begin());
        // 2.2 记录距离小数点有几位，也就是计算指数部分
        while (*num1.begin() == '0')
        {
            count -= 1;
            num1.erase(num1.begin());
        }
        // 3. 取前 n 位非 0 整数
        // 3.1 如果位数少于 n，补 0 
        if (num1.length() < n)
        {
            // 3.2 如果长度为 0，说明该数是 0
            if (num1.length() == 0)
            {
                count = 0;
            }
            while (n - num1.length())
            {
                num1 += '0';
            }
        }
        // .substr(pos, length)
        notationNum.setBase(num1.substr(0, n));
        notationNum.setIndex(count);
        
        return notationNum;
    }

    // 4.1 没有小数点，说明有整数部分
    else
    {
        string::iterator it = num1.begin();
        // 如果是 0，去除高位后，num1 直接没了
        while (*it != '.' && num1.length())
        {
            count += 1;
            it++;
            if (it == num1.end())
            {
                break;
            }
        }
        // 删除小数点
        if (it != num1.end() && num1.length())
        {
            num1.erase(it);
        }
        // 取前 n 位非 0 整数
        // 补 0 
        // 就算 num1 == 0，直接没了，也要补 0
        if (num1.length() < n)
        {
            while (n - num1.length())
            {
                num1 += '0';
            }
        }
        // .substr(pos, length)
        notationNum.setBase(num1.substr(0, n));
        notationNum.setIndex(count);

        return notationNum;
    }
}

int main()
{
    // 保留 n 位
    int n;
    // 第一个数字
    string num1;
    // 第二个数字
    string num2;
run:cout << "Input n: ";
    cin >> n;
    cout << "Input num1 and num2: ";
    cin >> num1 >> num2;

    Notation notationNum1 = turnToNotation(num1, n);
    Notation notationNum2 = turnToNotation(num2, n);

    if (notationNum1 == notationNum2)
    {
        cout << "YES. " << endl;
        cout << "0." << notationNum1.getBase() << " * 10^" << notationNum1.getIndex() << endl;
    }
    else
    {
        cout << "NO. " << endl;
        cout << "0." << notationNum1.getBase() << " * 10^" << notationNum1.getIndex() << endl;
        cout << "0." << notationNum2.getBase() << " * 10^" << notationNum2.getIndex() << endl; 
    }
    goto run;
    return 0;
}