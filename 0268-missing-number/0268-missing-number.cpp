class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0, n = nums.size();
        for(int i = 1; i <= n; i++)
            ans ^= i;
        for(auto &itr : nums)
            ans ^= itr;
        return ans;
    }
};