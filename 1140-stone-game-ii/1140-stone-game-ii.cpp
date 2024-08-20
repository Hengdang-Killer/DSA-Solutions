class Solution 
{
public:
    int stoneGameII(vector<int>& piles) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n+1, 0));
        vector<int> suf(n, 0);
        for(int i = n-1; i >= 0; i--)
        {
            suf[i] = piles[i];
            if(i != n-1)
                suf[i] += suf[i+1];
        }
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 2*j; k >= 1; k--)
                {
                    if(i + k >= n)
                    {
                        dp[i][j] = suf[i];
                        break;
                    }
                    dp[i][j] = max(dp[i][j], suf[i] - dp[i+k][max(k, j)]);
                }
            }
        }
        return dp[0][1];
    }
};