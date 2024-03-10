#include <iostream>

using namespace std;
// взагалі код клепав на швидку руку, як буде час то спробую його скоротити.
int main()
{
    // обчислення відстані s = v*t

    int v;
    cout << "Enter speed (v)" << endl;
    cin >> v;
    int t = 0;
    cout << "Enter time (t)" << endl;
    cin >> t;
    int s = v * t;

    //Обчислення  m = (x+y)/2

    int x, y;
    cout << "Enter x" << endl;
    cin >> x;
    cout << "Enter y" << endl;
    cin >> y;
    int m = (x + y) / 2.0;

    // Обчислення дискримінанту d = b^2 -4ac

    int a, b, c;
    cout << "Enter the value a > 0" << endl; // тут просто порахувати не треба робити тернарним оператором чи if else
    cin >> a;
    cout << "Enter the value b" << endl;
    cin >> b;
    cout << "Enter the value c" << endl;
    cin >> c;
    int d = (b * b) - 4 * (a * c);

    cout << "value (s)" << s << endl;
    cout << "value (m)" << m << endl;
    cout << "value (d)" << d << endl;

    return 0;
}
