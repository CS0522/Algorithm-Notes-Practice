/**
 * P247 简单计算器 
 * 中缀表达式，后缀表达式
*/

#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Symbol 
{
private: 
    double num;
    // 操作符
    char op;
    // 1: num
    // 0: operator
    bool isNum;
public:
    Symbol(double _num, bool _isNum) : num(_num), isNum(_isNum) {}

    void setNum(double _num)
    {
        this->num = _num;
    }
    void setOp(char _op)
    {
        this->op = _op;
    }
    void setIsNum(bool _isNum)
    {
        this->isNum = _isNum;
    }
    double getNum()
    {
        return this->num;
    }
    char getOp()
    {
        return this->op;
    }
    bool getIsNum()
    {
        return this->isNum;
    }
};

// 建立一个 Map 映射，设置优先级
map<char, int> priorityMap;

queue<Symbol> turnToPostfixExp(string infixExp)
{
/* 转换为后缀表达式
 * 设立一个操作符stack，一个数组或者队列存储后缀表达式
 * 扫描中缀表达式，碰到操作数，放入后缀表达式
 * 碰到操作符op，比较优先级：
    * 1. 如果op优先级高于操作符stack的栈顶优先级，则op压入栈
    * 2. 如果op优先级等于或者小于操作符stack的栈顶优先级，则stack不断出栈，直到满足1
 * 扫描完毕后，如果stack中还有元素，则全部加入到后缀表达式中
 * 可以用 Map 建立操作符号的优先级的映射
*/
    // init
    stack<char> operatorStack;
    queue<Symbol> postfixExp;

    Symbol temp(0.0, true);
    for (string::iterator it = infixExp.begin(); it != infixExp.end() + 1; it++)
    {
        // 如果扫到了空格，说明一个操作符或者一个数字结束了
        // 还要考虑当字符串结束时
        if (it == infixExp.end() || *it == ' ')
        {
            // 如果是数字，直接放入 postfixExp
            if (temp.getIsNum() == true)
            {
                postfixExp.push(temp);
            }
            // 如果是op
            else
            {
                // 如果op优先级等于或者小于操作符stack的栈顶优先级，则stack不断出栈
                while (!operatorStack.empty() && priorityMap[temp.getOp()] <= priorityMap[operatorStack.top()])
                {
                    Symbol tempOp(0.0, true);
                    tempOp.setIsNum(false);
                    tempOp.setOp(operatorStack.top());
                    operatorStack.pop();
                    postfixExp.push(tempOp);
                }
                // 如果op优先级高于操作符stack的栈顶优先级，或者栈为空，则op压入栈
                operatorStack.push(temp.getOp());
            }

            // 清除temp信息
            temp.setNum(0.0);
            temp.setIsNum(true);
        }
        // 数字
        else if (*it >= '0' && *it <= '9')
        {
            temp.setIsNum(true);
            temp.setNum(temp.getNum() * 10 + (*it - '0'));
        }
        // 操作符
        else 
        {
            temp.setIsNum(false);
            temp.setOp(*it);
        }
    }

    // 扫描完毕后，如果stack中还有元素，则全部加入到后缀表达式中
    while (!operatorStack.empty())
    {
        Symbol tempOp(0.0, true);
        tempOp.setIsNum(false);
        tempOp.setOp(operatorStack.top());
        postfixExp.push(tempOp);
        operatorStack.pop();
    }

    return postfixExp;
}

double calPostfixExp(queue<Symbol> postFixExp)
{
/* 计算后缀表达式
 * 如果是操作数，压入栈
 * 如果是操作符，栈弹出2个，计算，新值再压入栈
*/
    stack<Symbol> numStack;
    while (!postFixExp.empty())
    {
        Symbol temp = postFixExp.front();
        // 数字
        if (temp.getIsNum() == true)
        {
            numStack.push(temp);
        }
        // 操作符
        else
        {
            if (!numStack.empty())
            {
                Symbol num2 = numStack.top();
                numStack.pop();
                Symbol num1 = numStack.top();
                numStack.pop();
                Symbol newVal(0.0, true);
                newVal.setIsNum(true);
                // 计算
                if (temp.getOp() == '+')
                {
                    newVal.setNum(num1.getNum() + num2.getNum());
                }
                else if (temp.getOp() == '-')
                {
                    newVal.setNum(num1.getNum() - num2.getNum());
                }
                else if (temp.getOp() == '*')
                {
                    newVal.setNum(num1.getNum() * num2.getNum());
                }
                else if (temp.getOp() == '/')
                {
                    newVal.setNum(num1.getNum() / num2.getNum());
                }
                // 新值压入栈
                numStack.push(newVal);
            }
            
        }
        postFixExp.pop();
    }

    return ((!numStack.empty()) ? numStack.top().getNum() : 0.0);
}

int main()
{
    // init
    string infixExp;
    queue<Symbol> postfixExp;
    // 建立一个 Map 映射，设置优先级
    priorityMap.insert(make_pair('+', 1));
    priorityMap.insert(make_pair('-', 1));
    priorityMap.insert(make_pair('*', 2));
    priorityMap.insert(make_pair('/', 2));

    cout << "Input an infix expression(use blank to seperate each number and operator): " << endl;
    getline(cin, infixExp);

    // 转换为后缀表达式
    postfixExp = turnToPostfixExp(infixExp);
    // 计算后缀表达式
    double result = calPostfixExp(postfixExp);
    cout << "Result is: " << fixed << setprecision(2) << result << endl;

    

    return 0;
}