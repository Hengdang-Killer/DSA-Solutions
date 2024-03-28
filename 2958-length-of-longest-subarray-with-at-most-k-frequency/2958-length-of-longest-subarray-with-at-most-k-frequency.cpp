class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0, r = 0, cnt {};
        while(r < n)
        {
            int cur = nums[r++];
            mp[cur]++;
            while(l < r && mp[cur] > k)
                mp[nums[l++]]--;
            cnt = max(cnt, r - l);
        }
        return cnt;
    }
};