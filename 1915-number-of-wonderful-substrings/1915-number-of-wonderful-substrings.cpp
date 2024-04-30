class Solution 
{
public:
    long long wonderfulSubstrings(string word) 
    {
        unordered_map<int, int> count;
        count[0] = 1;
        long long result = 0;
        int bitmask = 0;
        for (char &ch : word) 
        {
            int charIndex = ch - 'a';
            bitmask ^= 1 << charIndex;
            result += count[bitmask];
            for (int i = 0; i < 10; i++) 
            {
                result += count[bitmask ^ (1 << i)];
            }
            count[bitmask]++;
        }
        return result;
    }
};