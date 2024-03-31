#pragma GCC optimize("O3", "unroll-loops")
class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long long ans = 0;
        int mxPos = -1, mnPos = -1, n = nums.size();
        for(int r = 0, l = 0; r < n; r++)
        {
            if (nums[r] < minK || nums[r] > maxK)
            {
                l = r + 1;
                continue;
            }
            if (nums[r] == maxK) 
                mxPos = r;
            if (nums[r] == minK) 
                mnPos = r;
            ans += max((min(mxPos, mnPos) - l + 1), 0);
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