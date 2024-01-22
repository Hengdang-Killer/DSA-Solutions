class Solution 
{
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int xr1 = 0, xr2 = 0;
        int n = nums.size(), cnt = 1;
        for(int i = 0; i < n; i++)
        {
            xr2 ^= cnt++;
            xr1 ^= nums[i];
        }
        int xrFinal = xr1 ^ xr2;
        int rightmostSetBit = xrFinal & -xrFinal;
        int xorSet = 0;
        int xorNotSet = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (i & rightmostSetBit) 
                xorSet ^= i;
            else 
                xorNotSet ^= i;
        }
        for (int num : nums) 
        {
            if (num & rightmostSetBit)
                xorSet ^= num;
            else
                xorNotSet ^= num;
        }
        for (int num : nums)
        {
            if (num == xorSet)
                return {xorSet, xorNotSet};
        }
        return {xorNotSet, xorSet};
    }
};