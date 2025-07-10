// The shift operator only work correctly with positive integers . For negative numbers right shift may not always behave as arith matic divison ( because of sign extension )

// For unsigned integers , both << and >> are safe and predictable

#include <iostream>
using namespace std;

int main()
{
    n = 16;

    int multiplied = n << 2; // 16*4 = 64
    int divided = n >> 2;    // 16/4 = 4

    cout << "Multiplied : " << multiplied << endl;
    cout << "Divided: " << divided << endl;

    return 0;
}