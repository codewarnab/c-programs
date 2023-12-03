// write a program un c++ using class and object to find out the sum 1 to n where n is a given integer 
#include <iostream>
using namespace std;

class Summation {
  private:
    int num;

  public:
    Summation(int n) {
      num = n;
    }

    int calculate() {
      int sum = 0;
      for (int i = 1; i <= num; i++) {
        sum += i;
      }
      return sum;
    }
};

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;

  Summation s(n);
  int result = s.calculate();

  cout << "The sum of 1 to " << n << " is " << result << endl;

  return 0;
}
