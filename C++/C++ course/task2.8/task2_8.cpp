#include <iostream>

using namespace std;

int main()
{
    int number, sum = 0;
    while(true)
    {
        cout << "Enter the number" << endl;
        cin >> number;
        if (number >= 0)
        {
         sum += number;
        }
        else
        {
         break;
        }
        cout << "Sum is:" << sum << endl;
    }
}
