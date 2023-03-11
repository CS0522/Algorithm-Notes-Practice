/**
 * P86
*/

#include <iostream>
using namespace std;

int main()
{
    int schoolNum;
    cout << "Input school number: ";
    cin >> schoolNum;
    // dynamic array
    int *schoolArray = new int(schoolNum);
    // read the score
    for (int i = 0; i < schoolNum; i++)
    {
        int schoolId;
        int schoolScore;
        cin >> schoolId >> schoolScore;
        if (schoolId >= schoolNum)
        {
            cout << "Invalid id. " << endl;
            return 0    ;
        }
        schoolArray[schoolId] += schoolScore;
    }
    // get max score
    int maxScore = 0;
    int maxId = 0;
    for (int j = 0; j < schoolNum; j++)
    {
        if (schoolArray[j] > maxScore)
        {
            maxScore = schoolArray[j];
            maxId = j;
        }
    }

    cout << "Max school id and score is: " << maxId << " " << maxScore << endl;

    return 0;
}