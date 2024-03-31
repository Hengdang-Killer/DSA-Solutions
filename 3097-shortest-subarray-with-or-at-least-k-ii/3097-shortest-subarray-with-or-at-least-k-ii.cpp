class Solution 
{
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> mp(32, 0);
        int ans = n + 1;
        for(int l = 0, r = 0; r < n; r++)
        {
            int val = 0;
            for(int i = 0; i < 32; i++)
            {    
                if((nums[r]>>i & 1)) 
                    mp[i]++;
                if(mp[i])
                    val |= 1 << i;
            }
            while(val >= k && l <= r)
            {
                ans = min(ans, r - l + 1);
                val = 0;
                for(int i = 0; i < 32; i++)
                {
                    if((nums[l]>>i & 1))
                        mp[i]--;
                    if(mp[i])
                        val |= 1<<i;
                }
                l++;
            }
        }
        if(ans > n)
            ans = -1;
        return ans;
    }
};