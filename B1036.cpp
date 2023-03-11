/**
 * P89 画正方形
*/

#include <iostream>
using namespace std;

/**
 * n: column number
*/
void drawFunc(int n)
{
    int col = n;
    int row = col % 2 == 0 ? col / 2 : (col / 2) + 1;

    // 1st row
    for (int i = 0; i < col; i++)
    {
        cout << "a";
    }
    cout << endl;
    // 2nd ~ (row-1)th rows
    for (int j = 0; j < row - 2; j++)
    {
        cout << "a";
        for (int k = 0; k < col - 2; k++)
        {
            cout << " ";
        }
        cout << "a" << endl;
    }
    // last row
    for (int l = 0; l < col; l++)
    {
        cout << "a";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    drawFunc(n);

    return 0;
}