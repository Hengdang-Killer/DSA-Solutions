class Solution 
{
public:
    int countSubstrings(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.length(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for (int len = 1; len <= n; ++len) 
        {
            for (int i = 0; i < n - len + 1; ++i) 
            {
                if (s[i] == s[i + len - 1] && (len <= 2 || dp[i + 1][i + len - 2])) 
                {
                    dp[i][i + len - 1] = true;
                    ans++;
                }
            }
        }
        return ans; 
    }
};