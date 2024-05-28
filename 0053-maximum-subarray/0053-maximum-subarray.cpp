class Solution 
{
private:
    bool allNegative(vector<int> &nums)
    {
        for(auto &itr : nums)
            if(itr >= 0) return 0;
        return 1;
    }
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(allNegative(nums))
            return *max_element(nums.begin(), nums.end());
        int sum = 0, ans = 0;
        for(auto &itr : nums)
        {
            sum += itr;
            if(sum < 0)
                sum = 0;
            ans = max(ans, sum);
        }
        return ans;
    }
};