#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums = {2, 4, 6, 8};

    bool allEven = std::all_of(nums.begin(), nums.end(), [](int x)
                               { return x % 2 == 0; });

    std::
            cout
        << (allEven ? "ALl are even " : "Not all are even") << std::endl;

    bool hasOdd = std::any_of(nums.begin(), nums.end(), [](int x)
                              { return x % 2 != 0; });

    bool noneNegative = std::none_of(nums.begin(), nums.end(), [](int x)
                                     { return x < 0; });

    return 0;
}