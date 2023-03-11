/**
 * P85
*/

#include <iostream>
using namespace std;

int callatzFunc(int n) 
{
    int count = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = (3 * n + 1) / 2;
        }

        count += 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << "Output: " << callatzFunc(n) << endl;

    return 0;
}