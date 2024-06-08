class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[sum] = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            if(mp.find(sum) != mp.end())
            {
                if(i - mp[sum] > 1)
                    return 1;
            }
            else
                mp[sum] = i;
        }
        return 0;
    }
};