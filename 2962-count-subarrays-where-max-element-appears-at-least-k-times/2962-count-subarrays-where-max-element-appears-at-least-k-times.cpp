class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long mx = *max_element(nums.begin(),nums.end()), cnt = 0, ans = 0;
        int l = 0, r = 0;
        while(r < nums.size())
        {
            if(nums[r] == mx)
                cnt++;
            while(cnt >= k)
            {
                if(nums[l] == mx)
                    cnt--;
                l++;
                ans += nums.size() - r;
            }    
            r++;
        }
        return ans;    
    }
};