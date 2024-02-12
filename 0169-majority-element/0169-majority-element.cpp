class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto &itr : nums)
        {
            mp[itr]++;
            if(mp[itr] > n/2)
                return itr;
        }    
        return 1;
    }
};