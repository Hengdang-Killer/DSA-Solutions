class Solution 
{
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            string s = to_string(nums[i]), t;
            for(int j = 0; j < s.size(); j++)
                t.push_back(mapping[s[j] - '0'] + '0');
            int val = 0;
            if(t.size() > 0)
                val = stoi(t);
            mp[val].push_back(nums[i]);
        }
        vector<int> ans;
        for(auto &itr : mp)
        {
            for(auto &itr2 : itr.second)
                ans.push_back(itr2);
        }
        return ans;
    }
};