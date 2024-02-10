class Solution 
{
public:
    int returnToBoundaryCount(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0, sum = 0;
        for(auto &itr : nums)
        {
            sum += itr;
            if(sum == 0)
                ans++;
        }
        return ans;
    }
};