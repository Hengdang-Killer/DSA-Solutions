class Solution 
{
public:
    int minSwaps(vector<int>& nums) 
    {
        int n = nums.size(), cnt = 0;
        for (int &itr : nums) 
            cnt += itr;
        if (cnt == 0 || cnt == n) 
            return 0;
        int cur = 0;
        for (int i = 0; i < cnt; i++) 
            cur += nums[i];
        int mx = cur;
        for (int i = 0; i < n; i++) 
        {
            cur -= nums[i];
            cur += nums[(i + cnt) % n];
            mx = max(mx, cur);
        }
        return cnt - mx;
    }
};