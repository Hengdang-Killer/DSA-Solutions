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
        vector<int> par[n], nxt(n), sz(n, 0);
        for(int i = 0; i < n; i++)
        {
            int mn = 1e9+7;
            for(int j = i+1; j < n; j++)
            {
                if(nums[j] % nums[i] == 0)
                {
                    mn = min(mn, nums[j]), par[j].push_back(i);
                }
            }
        }
        int mx = -1, idx;
        for(int i = n-1; i >= 0; i--)
        {
            for(auto itr : par[i])
            {
                if(sz[itr] < sz[i] + 1)
                    sz[itr] = sz[i]+1, nxt[itr] = i;
            }
            if(sz[i] >= mx)
                mx = sz[i], idx = i;
        }
        mx++;
        vector<int> ans;
        while(mx--)
        {
            ans.push_back(nums[idx]);
            idx = nxt[idx];
        }
        return ans;
    }
};