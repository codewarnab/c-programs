// // program to check if a number is even or odd 

// #include <iostream>

// using namespace std;

// class check {
//     private :
//     int number ;
//     public :
//     void setnumber (int x )
//     {
//         number = x;
//     }
//     void eoro ()
//     {
//         if (number%2==0)
//         std::cout << "this is an even number " << std::endl;
//         else 
//         std::cout << "this is an odd number " << std::endl;
//     }
// };



//  int main(int argc, const char** argv) {
//  check check1;
//  int x;
//  std::cout << "Enter the number to check" << std::endl;
//  cin>>x;
//  check1.setnumber(x);
//  check1.eoro();
 
//     return 0;
// }
#include <iostream>
using namespace std;

class EvenOddChecker {
  public:
    void check(int num) {
      if (num % 2 == 0) {
        cout << num << " is even." << endl;
      } else {
        cout << num << " is odd." << endl;
      }
    }
};

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  EvenOddChecker checker;
  checker.check(num);

  return 0;
}
