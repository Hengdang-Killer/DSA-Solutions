class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size(), cnt = 0;
        vector<int> ans(n, 0);
        for(auto &itr : nums)
        {
            if(itr == 0)
                cnt++;
        }
        if(cnt > 1)
            return ans;
        ans[n-1] = 1;
        for(int i = n-2; i >= 0; i--)
        {
            ans[i] = nums[i+1]*ans[i+1];
        }
        for(int i = 1; i < n; i++)
        {
            ans[i] *= nums[i-1];
            nums[i] *= nums[i-1];
        }
        return ans;
    }
};