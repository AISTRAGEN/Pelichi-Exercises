#include "math_header.h"
#include <iostream>
using namespace std;

int main() {
  // обчислення відстані s = v*t

  int v;
  cout << "Enter speed (v)" << endl;
  cin >> v;
  int t = 0;
  cout << "Enter time (t)" << endl;
  cin >> t;

  // Обчислення  m = (x+y)/2

  int x, y;
  cout << "Enter x" << endl;
  cin >> x;
  cout << "Enter y" << endl;
  cin >> y;

  // Обчислення дискримінанту d = b^2 -4ac

  int a, b, c;
  cout << "Enter the value a > 0"
       << endl; // тут просто порахувати не треба робити тернарним оператором чи
                // if else
  cin >> a;
  cout << "Enter the value b" << endl;
  cin >> b;
  cout << "Enter the value c" << endl;
  cin >> c;

  cout << "value (s)" << speed(v, t) << endl;
  cout << "value (m)" << equation(x, y) << endl;
  cout << "value (d)" << discriminant(a, b, c) << endl;

  return 0;
}
