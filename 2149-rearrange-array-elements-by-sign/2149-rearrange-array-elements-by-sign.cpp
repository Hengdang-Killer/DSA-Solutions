class Solution 
{
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i = 0, j = 1, n = nums.size();
        vector<int> ans(n);
        for(auto &itr : nums)
        {
            if(itr >= 0)
            {
                ans[i] = itr;
                i += 2;
            }
            else
            {
                ans[j] = itr;
                j += 2;
            }
        }    
        return ans;
    }
};