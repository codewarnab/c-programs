#include<iostream>
#include<numeric> // for std::gcd 

int main(){
    int a = 36;
    int b = 60;

    int result = std::gcd(a, b);

    std::cout << "GCD of " << a << " and " << b << " is " << result << std : endl;

    return 0; 
}