
#include <iostream>

using namespace std;

int main() {
  const double pi = 3.14159;

  double R;

  cout << "Enter Radius:" << endl;
  cin >> R;
  double S = pi * (R * R);

  cout << "Result"
       << " " << S << endl;
}
