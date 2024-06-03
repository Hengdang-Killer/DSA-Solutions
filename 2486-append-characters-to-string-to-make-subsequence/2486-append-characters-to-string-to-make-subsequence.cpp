class Solution 
{
public:
    int appendCharacters(string &s, string &t) 
    {
        vector<set<int>> pos(26);
        for(int i = 0; i < s.size(); i++)
        {
            pos[s[i]-'a'].insert(i);
        }
        int ans = 0, lastPos = -1;
        for(int i = 0; i < t.size(); i++)
        {
            auto itr = pos[t[i]-'a'].upper_bound(lastPos);
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