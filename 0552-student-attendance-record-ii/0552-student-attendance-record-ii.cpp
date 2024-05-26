class Solution 
{
    const int mod = 1e9+7;
    int dp[100001][2][3];
    int recursion(int i, int absent, int late)
    {
        if (absent >=2 || late >= 3) 
            return 0;
        if (i == 0) 
            return 1;
        if (dp[i][absent][late] != -1) 
            return dp[i][absent][late];
        int ans = recursion(i-1, absent, 0); // P
        ans %= mod;
        ans += (late < 2 ? recursion(i-1, absent, late+1) : 0); // L
        ans %= mod;
        ans += (absent == 0 ? recursion(i-1, absent+1, 0) : 0); // A
        return dp[i][absent][late] = ans % mod;
    }
public:
    int checkRecord(int n) 
    {
        fill(&dp[0][0][0], &dp[0][0][0]+(n+1)*6, -1);
        return recursion(n, 0, 0);
    }
};