class Solution 
{
    // so, pre[i] - pre[j-1] % k == 0
    // i.e., (t*k + r1 - p*k + r2) % k == 0
    // r1 == r2
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int sum = 0;
        vector<int> mp(k, 0);
        mp[sum]++;
        int ans = 0;
        for(auto &itr : nums)
        {
            sum = (sum + itr % k + k)%k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};