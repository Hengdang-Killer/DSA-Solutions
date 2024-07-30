class Solution 
{
public:
    int minimumDeletions(string s) 
    {
        int n = s.size();
        vector<int> dp(n+1, 0);
        int b_cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
                dp[i+1] = dp[i], b_cnt++;
            else
                dp[i+1] = min(dp[i] + 1, b_cnt);
        }
        return dp[n];
    }
};