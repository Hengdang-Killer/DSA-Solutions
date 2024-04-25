class Solution 
{
public:
    int longestIdealString(string s, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(k == 25)
            return s.size();
        int n = s.size();
        vector<int> v(26, -1);
        int ans = 0, cur = 0;
        for(int i = 0; i < n; i++)
        {
            cur = 0;
            for(int j = 0; j < 26; j++)
            {
                if(v[j] >= 0 && abs(j - (s[i]-'a')) <= k)
                    cur = max(cur, v[j]);
            }
            cur++;
            v[s[i]-'a'] = cur;
            ans = max(ans, cur);
        }
        return ans;
    }
};