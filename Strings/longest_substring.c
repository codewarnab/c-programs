// 1. Longest Substring Without Repeating Characters
// Problem : Given a string s,
// find the length of the longest substring without repeating characters.Example : Input : "abcabcbb" Output : 3("abc")

int longestSubstr(char str[])
{
    int maxLen = 0;
    int start = 0;
    index[256] = {-1}; // this is last seen index not the frequency counter

    for (int end = 0; str[end] != '\0'; end++)
    {
        char ch = str[end];

        if (index[(unsigned int)ch] >= start)
        {
            start = index[(unsigned int)ch] + 1;
        }

        index[(unsigned char)ch] = end; // update last seen index
        int currLen = end - start + 1;
        if (currLen > maxLen)
            maxLen = currLen;
    }
    return maxLen;
}

int main()
{

    char str[1000];
    prinf("Enter the string: ");
    scanf("%s", &str);
    int MaxLen = longestSubstr(str);
    return 0;
}
