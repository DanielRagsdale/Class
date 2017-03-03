#include <iostream>
#include "hw6.h"
using namespace std;
int main() {

  //String tests
  
  int a, b;
  cout << "Input 2 integers:\n";
  cin >> a; cin >> b;
  cout << "a^b=" << ipow(a, b) << ".\n";

  int n;
  cout << "Input array length:\n";
  cin >> n;
  double* d_array = new double[n];
  for (int i = 0; i < n; i++) {
    cout << "Input number (count " << (i+1) << "):\n";
    cin >> d_array[i];
  }
  cout << "The minimum among all inputs is " << my_min(d_array, n) << ".\n";
  delete[] d_array;
  
  double x, y;
  cout << "Input the x and y coordinates\n";
  cin >> x; cin >> y;
  cout << "The angle x and y makes with the origin is " << angle(x, y) << ".\n";

}
