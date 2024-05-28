class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};