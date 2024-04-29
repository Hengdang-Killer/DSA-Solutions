class Solution 
{
public:
    int minOperations(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int finalXor = 0;
        for (int &n : nums) 
        {
            finalXor ^= n;
        }
        int count = 0;
        while (k || finalXor) 
        {
            if ((k % 2) != (finalXor % 2))
                count++;
            k /= 2;
            finalXor /= 2;
        }
        return count;
    }
};