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
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int val = 0;
            for(int j = 0; j < 26; j++)
            {
                if(v[j] >= 0 && abs(j - (s[i]-'a')) <= k)
                {
                    val = max(val, dp[v[j]]);
                }
            }
            v[s[i]-'a'] = i;
            dp[i] = val + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};