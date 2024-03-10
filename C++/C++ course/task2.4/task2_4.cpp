#include <iostream>
using namespace std;
int main() {
  int temperature;
  cout << "Enter the temperature" << endl;
  cin >> temperature;

  if (temperature < 0) {
    cout << "Ice" << endl;
  } else if (temperature > 100) {
    cout << "Gas" << endl;
  }
  if (temperature >= 0 && temperature <= 100) {
    cout << "Water" << endl;
  }
}
