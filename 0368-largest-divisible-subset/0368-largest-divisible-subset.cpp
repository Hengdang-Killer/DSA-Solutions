class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> par(n), sz(n, 1);
        int mx = 0, idx;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(nums[j] % nums[i] == 0)
                {
                    if(sz[j] < sz[i] + 1)
                        sz[j] = sz[i]+1, par[j] = i;
                }
            }
            if(sz[i] >= mx)
                mx = sz[i], idx = i;
        }
        vector<int> ans;
        while(mx--)
        {
            ans.push_back(nums[idx]);
            idx = par[idx];
        }
        return ans;
    }
};