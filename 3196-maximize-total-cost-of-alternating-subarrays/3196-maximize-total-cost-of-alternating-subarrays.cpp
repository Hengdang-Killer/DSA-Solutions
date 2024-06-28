class Solution 
{
private:
    long long recursion(int i, int j, int &n, vector<int> &nums, vector<vector<long long>> &dp)
    {
        if(i >= n)
            return 0;
        if(dp[i][j] != -1e18)
            return dp[i][j];
        long long newSubArray = nums[i] + recursion(i+1, 1, n, nums, dp);
        long long oldSubArray = 0;
        if(j == 1)
            oldSubArray = -nums[i] + recursion(i+1, 0, n, nums, dp);
        else
            oldSubArray = nums[i] + recursion(i+1, 1, n, nums, dp);
        return dp[i][j] = max(newSubArray, oldSubArray);
    }
public:
    long long maximumTotalCost(vector<int>& nums) 
    {
        long long ans = 0;    
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1e18));
        return recursion(0, 0, n, nums, dp);
    }
};