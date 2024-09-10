class Solution 
{
public:
    long long findMaximumScore(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)
            return 0;
        vector<int> pre(n);
        int mx = nums[0], idx = 0; 
        for(int i = 1; i < n; i++)
        {
            pre[i] = idx;
            if(nums[i] > mx)
                mx = nums[i], idx = i;
        }
        long long ans = 0;
        int cur = n-1, prev = pre[n-1];
        while(1)
        {
            ans += (1LL*cur - 1LL*prev)*(nums[prev]*1LL);
            cur = prev;
            if(cur == 0)
                break;
            prev = pre[cur];
        }
        return ans;
    }
};