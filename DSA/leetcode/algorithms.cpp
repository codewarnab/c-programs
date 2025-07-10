#include <iostream>
#include <vector>
#include <algorithm> // For sort , reverse , find , binary_search , lower_bound  , upper_bound
#include <numeric>   // For accumulate

int main()
{
    std::vector<int> numbers = {5, 2, 8, 1, 9, 4, 7, 3, 6};
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted Numbers :";
    for (int x : numbers)
        std::cout << x << " ";

    std::reverse(numbers.begin(), numbers.end());
    std::cout << "Reversed numbers: ";

    for (int x : numbers)
        std::cout << x << " ";

    auto it_find = std::find(numbers.begin(), numbers.end(), 5);
    if (it_find != numbers.end())
    {
        std::cout << "Found 5 at position: " << std::distance(numbers.begin(), it_find) << std::endl;
    }

    std::sort(numbers.begin(), numbers.end()); // Sort again for binary_search
    std::cout << "Is 5 in sorted numbers? " << (std::binary_search(numbers.begin(), numbers.end(), 5) ? "Yes" : "No") << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum of numbers: " << sum << std::endl;

    return 0;
}
