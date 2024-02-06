class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<string, vector<string>> mp;
        for(string s: strs)
        {
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto itr : mp)
        {
            ans.push_back(itr.second);
        }
       return ans;
    }
};