#include <iostream>
#include <string>
#include <sstream> // For istringsstream
#include <vector>

int main()
{
    // Concatenation
    std::string s1 = "Hello";
    std::string s2 = " World";
    std::string s3 = s1 + s2;
    std::cout << "Concatenation: " << s3 << std::endl;
    s1.append("!");
    std::cout << "Append: " << s1 << std::endl;

    std::string sentence = "The quick brown fox ";
    std::string word = sentence.substr(4, 5); // start at index 4 , length 5
    std::cout << "Substring: " << word << std::endl;

    size_t pos = sentence.find("quick");
    if (pos != std::string::npos)
    {
        std::cout << "quick' fount at positon:" << pos << std::endl;
    }

    return 0;
}