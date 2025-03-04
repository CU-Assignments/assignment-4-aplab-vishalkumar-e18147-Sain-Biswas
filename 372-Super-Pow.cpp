class Solution
{
public:
    const int MOD = 1337;

    int modPow(int a, int k)
    {
        a %= MOD;
        int result = 1;
        for (int i = 0; i < k; ++i)
        {
            result = (result * a) % MOD;
        }
        return result;
    }

    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;

        int lastDigit = b.back();
        b.pop_back();

        int part1 = modPow(superPow(a, b), 10);
        int part2 = modPow(a, lastDigit);

        return (part1 * part2) % MOD;
    }
};