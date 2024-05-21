class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        vector<int> v;
        for(int i = 0; i < (1 << nums.size()); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if(((1 << j)&i) > 0)
                {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};