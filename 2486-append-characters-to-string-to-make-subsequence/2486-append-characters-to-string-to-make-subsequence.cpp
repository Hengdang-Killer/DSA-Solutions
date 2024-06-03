class Solution 
{
public:
    int appendCharacters(string &s, string &t) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i++)
        {
            pos[s[i]-'a'].push_back(i);
        }
        int ans = 0, lastPos = -1;
        for(int i = 0; i < t.size(); i++)
        {
            auto itr = upper_bound(pos[t[i]-'a'].begin(), pos[t[i]-'a'].end(), lastPos);
            if(itr == pos[t[i]-'a'].end())
            {
                ans = t.size() - i;
                break;
            }
            else
                lastPos = *itr;
        }
        return ans;
    }
};