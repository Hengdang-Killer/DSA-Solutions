class Solution 
{
public:
    long long maximumTotalCost(vector<int>& nums) 
    {
        long long ans = 0;    
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long> (2, 0));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j < 2; j++)
            {
                long long newSubArray = nums[i] + dp[i+1][1];
                long long oldSubArray = 0;
                if(j == 1)
                    oldSubArray = -nums[i] + dp[i+1][0];
                else
                    oldSubArray = nums[i] + dp[i+1][1];
                dp[i][j] = max(newSubArray, oldSubArray);
            }
        }
        return dp[0][0];
    }
};