/* Memoisation
class Solution {
public:
    int func(int cur, vector<int> &nums, vector<int> &dp)
    {
        if(cur < 0)
        {
            return 0;
        }
        if(dp[cur] != -1)
            return dp[cur];
        return dp[cur] = max(func(cur-2,nums,dp) + nums[cur], func(cur-1,nums,dp));

    }
    int rob(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        vector<int> dp(nums.size(),-1);
        return func(nums.size()-1,nums,dp);    
    }
};*/
/* Tabulation
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }    
        return dp[nums.size() - 1];
    }
};*/
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        if(nums.size() == 1)
            return nums[0];
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]), curr;
        for(int i = 2; i < nums.size(); i++)
        {
            curr = max(prev2 + nums[i], prev1);
            prev2 = prev1, prev1 = curr;
        }    
        return prev1;
    }
};