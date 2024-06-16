class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long miss = 1;
        int ans = 0, i = 0;
        while (miss <= n) 
        {
            if (i < nums.size() && nums[i] <= miss) 
                miss += nums[i++];
            else
                miss += miss, ans++;
        }
        return ans;
    }
};