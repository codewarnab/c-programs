#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // using a lamda function with std:: for_each to print elements
    std::cout << "Elements using lamda: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n)
                  { std::cout << n << " "; })

            std::cout
        << std::endl;

    // using a lamda function with std::count_if to count even numbers

    int even_count = std::count_if(numbers.begin(), numbers.end(), [](int n)
                                   { return n % 2 == 0; })

                         std::cout
                     << "Numbers of even elements: " << even_count << std::endl;

    // Lamda with capture  by value
    int x = 5;
    std::for_each(numbers.begin(), numbers.end(), [x](int n)
                  {
            if(n>x){
                std::cout << n << " is greater than " << x << std::endl;
            } })

        return 0;
}