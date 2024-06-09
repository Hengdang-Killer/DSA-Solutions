class Solution 
{
    // so, pre[i] - pre[j-1] % k == 0
    // i.e., (t*k + r1 - p*k + r2) % k == 0
    // r1 == r2
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int sum = 0;
        unordered_map<int, int> mp;
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