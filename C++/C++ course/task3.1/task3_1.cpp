#include <iostream>
#include <string>
using namespace std;

void hello ()
{
    string name;
    cout << "Enter the name" << endl;
    cin >> name;
    cout << "Hello" << " " << name << " " << "World" << "!" << endl;

}
int main()
{
   hello();
}