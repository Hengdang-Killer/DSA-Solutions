class Solution 
{
public:
    vector<string> uncommonFromSentences(string &s1, string &s2) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<string, int> mp;
        string cur = "";
        for(auto &itr : s1)
        {
            if(itr == ' ')
                mp[cur]++, cur = "";
            else
                cur.push_back(itr);
        }
        if(cur.size() > 0)
            mp[cur]++;
        cur = "";
        for(auto &itr : s2)
        {
            if(itr == ' ')
                mp[cur]++, cur = "";
            else
                cur.push_back(itr);
        }
        if(cur.size() > 0)
            mp[cur]++;
        vector<string> ans;
        for(auto &itr : mp)
        {
            if(itr.second == 1)
                ans.push_back(itr.first);
        }
        return ans;
    }
};