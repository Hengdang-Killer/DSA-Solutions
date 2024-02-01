class Solution 
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n = nums.size(), j = 0;
        sort(nums.begin(), nums.end());    
        vector<vector<int>> ans(n/3, vector<int>(3, 0));
        for(int i = 0; i < n; i++)
        {
            if(i%3 == 0)
            {
                ans[j][i%3] = nums[i];
            }
            if(i%3 == 1)
            {
                if(nums[i] - nums[i-1] > k)
                    return {};                    
                ans[j][i%3] = nums[i];
            }
            if(i%3 == 2)
            {
                if(nums[i] - nums[i-2] > k)
                    return {};
                ans[j][i%3] = nums[i];
                j++;
            }
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();