class Solution
{
public:
    string longestNiceSubstring(string s)
    {
        set<char> charSet;

        for (char c : s)
        {
            charSet.insert(c);
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (charSet.find((char)tolower(s[i])) == charSet.end() || charSet.find((char)toupper(s[i])) == charSet.end())
            {
                string part1 = longestNiceSubstring(s.substr(0, i));
                string part2 = longestNiceSubstring(s.substr(i + 1));

                return (part1.length() < part2.length()) ? part2 : part1;
            }
        }

        return s;
    }
};