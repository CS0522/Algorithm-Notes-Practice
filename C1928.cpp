/**
 * P91 日期差距计算
*/

#include <iostream>
using namespace std;

// 数组表示[平年, 闰年]每个月的天数
int month[12][2] = {
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};

// 判断是否是闰年：可以被4整除，而不能被100整除，或者可以被400整除
int isLeapYear(int year)
{
    // 闰年
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    // 平年
    return 0;
}

// calculate function
int calculateFunc(int timeMin, int timeMax)
{
    if (timeMin == timeMax)
    {
        return 0;
    }
    if (timeMax < timeMin)
    {
        // change
        int temp = timeMax;
        timeMax = timeMin;
        timeMin = temp;
    }
    int ymin = timeMin / 10000;
    int ymax = timeMax / 10000;
    int mmin = (timeMin % 10000) / 100;
    int mmax = (timeMax % 10000) / 100;
    int dmin = timeMin % 100;
    int dmax = timeMax % 100;
    // 通过不断增加timeMin，使其与timeMax值相等
    // start
    int step = 1;
    while (ymin < ymax || mmin < mmax || dmin < dmax)
    {
        // day ++
        dmin += 1;
        // 进位
        if (dmin == month[mmin][isLeapYear(ymin)] + 1)
        {
            mmin += 1;
            dmin = 1;
        }
        if (mmin == 12 + 1)
        {
            ymin += 1;
            mmin = 1;
        }

        // step ++
        step += 1;
    }

    return step;
}

int main()
{
    int time1, time2;
    cout << "Input time1(YYYYMMDD): ";
    cin >> time1;
    if (time1 % 100 < 1 || time1 % 100 > 31)
    {
        cout << "invalid format." << endl;
        return 0;
    }
    cout << "Input time2(YYYYMMDD): ";
    cin >> time2;
    if (time2 % 100 < 1 || time2 % 100 > 31)
    {
        cout << "invalid format." << endl;
        return 0;
    }
    int result = calculateFunc(time1, time2);
    cout << "difference: " << result << endl;

    return 0;
}