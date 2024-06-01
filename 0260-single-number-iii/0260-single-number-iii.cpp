class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int testNum = 0;
        for(auto &itr : nums)
            testNum ^= itr;
        vector<int> ans(2, 0);
        int pos = 0;
        for(int i = 31; i >= 0; i--)
        {
            if((testNum >> i) & 1)
            {
                pos = i;
                break;
            }
        }
        for(auto &itr : nums)
        {
            if((itr >> pos) & 1)
                ans[0] ^= itr;
        }
        ans[1] = ans[0]^testNum;
        return ans;
    }
};