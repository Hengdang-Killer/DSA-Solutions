class Solution 
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0, ans = 0;
        for (int &itr : nums) 
        {
            sum += itr;
            if (freq.find(sum - goal) != freq.end()) 
                ans += freq[sum - goal];
            freq[sum]++;
        }
        return ans;
    }
};