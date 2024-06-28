class Solution 
{
public:
    long long maximumTotalCost(vector<int>& nums) 
    { 
        int n = nums.size();
        long long prev0 = 0, prev1 = 0;
        for(int i = n-1; i >= 0; i--)
        {
            long long cur1 = max(-nums[i] + prev0, nums[i] + prev1);
            long long cur0 = max(nums[i] + prev1, nums[i] + prev1);
            prev0 = cur0, prev1 = cur1;
        }
        return prev0;
    }
};