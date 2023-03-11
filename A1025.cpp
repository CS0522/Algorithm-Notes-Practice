/**
 * P103 Score Ranking
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 300

using namespace std;

// define structure
/*
typedef struct Student {
    // 13 digits, so cannot use 'int'
    string registerNumber;
    // score
    int score;
    // location
    int locationNumber;
    // location rank
    int locationRank;
};
*/

class Student {
private:
    // 考号
    string registerNumber;
    // 分数
    int score;
    // 考场号
    int locationNumber;
    // 考场内排名
    int locationRank;

public:
    // constructor
    Student(string registerNumber, int score, int locationNumber)
    {
        this->score = score;
        this->registerNumber = registerNumber;
        this->locationNumber = locationNumber;
    }

    // getter and setter
    string getRegisterNumber()
    {
        return this->registerNumber;
    }

    int getScore()
    {
        return this->score;
    }

    int getLocationNumber()
    {
        return this->locationNumber;
    }

    int getLocationRank()
    {
        return this->locationRank;
    }

    void setRegisterNumber(string registerNumber)
    {
        this->registerNumber = registerNumber;
    }

    void setScore(int score)
    {
        this->score = score;
    }

    void setLocationNumber(int locationNumber)
    {
        this->locationNumber = locationNumber;
    }

    void setLocationRank(int locationRank)
    {
        this->locationRank = locationRank;
    }
};

// sort(first_loaction, the_next_of_last_location, cmp_function)的比较函数
bool cmp(Student a, Student b)
{
    // a b分数不同，则按分数从大到小
    if (a.getScore() != b.getScore())
    {
        return a.getScore() > b.getScore();
    }
    // 分数相同，按照 registerNumber 字典序从小到大
    else 
    {
        return (a.getRegisterNumber()< b.getRegisterNumber());
    }
}

void rankFunction(int &locationTotal, int &studentTotal, vector<Student> &studentList)
{
    cout << "Input location number: ";
    cin >> locationTotal;
    // 循环按考场添加
    for (int i = 1; i <= locationTotal; i++)
    {
        // 考场内的人数
        int k;
        cout << "Input testee number of this location: ";
        cin >> k;
        // 循环添加学生信息
        for (int j = 0; j < k; j++)
        {
            string registerNumber;
            int score;
            cout << "Input testee's info: ";
            cin >> registerNumber >> score;
            // set info and push into vector
            studentList.push_back(Student(registerNumber, score, i));

            studentTotal += 1;
        }
        // 考场内进行排序
        // 第一个是起始元素，第二个是尾元素的下一个地址，最后一个是比较函数
        sort(studentList.begin() + studentTotal - k, studentList.begin() + studentTotal, cmp);
        // set student's locationRank
        for (int m = studentTotal - k; m < studentTotal; m++)
        {
            // 第一个学生
            if (m == studentTotal - k)
            {
                studentList[m].setLocationRank(1);
            }
            // 其他学生
            else
            {
                // 如果分数跟前面一个同学的分数相同，则排名一致
                if (studentList[m].getScore() == studentList[m - 1].getScore())
                {
                    studentList[m].setLocationRank(studentList[m - 1].getLocationRank());
                }
                else
                {
                    studentList[m].setLocationRank(m - studentTotal + k + 1);
                }
            }
        }
    }
    // 对整个vector进行排序
    sort(studentList.begin(), studentList.end(), cmp);
}

int main()
{
    // 考场的总数
    int locationTotal;
    // 考生总人数
    int studentTotal = 0;
    // Student Array
    vector<Student> studentList;
    // function
    rankFunction(locationTotal, studentTotal, studentList);
    // rank value
    int rank = 1;
    // print out
    for (int i = 0; i < studentTotal; i++)
    {
        if (i > 0 && studentList[i - 1].getScore() != studentList[i].getScore())
        {
            rank = i + 1;
        }
        cout << studentList[i].getRegisterNumber() << " " << rank << " "
            << studentList[i].getLocationNumber() << " " << studentList[i].getLocationRank() << endl;
    }

    return 0;
}