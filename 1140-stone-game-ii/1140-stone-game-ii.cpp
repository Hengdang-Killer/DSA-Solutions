class Solution 
{
private:
    int recursion(int i, int j, int n, vector<int> &suf, vector<int> &piles, vector<vector<int>> &dp)
    {
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int val = 0, sum = 0;
        for(int k = 1; k <= 2*j; k++)
        {
            if(i + k - 1 >= n)
                break;
            sum += piles[i + k - 1];
            int nxtM = max(k, j);
            val = max(val, suf[i] - recursion(i + k, nxtM, n, suf, piles, dp));
        }
        return dp[i][j] = val;
    }
public:
    int stoneGameII(vector<int>& piles) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = piles.size();
        vector<int> suf(n, 0);
        for(int i = n-1; i >= 0; i--)
        {
            if(i != n-1)
                suf[i] += suf[i+1];
            suf[i] += piles[i];
        }
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return recursion(0, 1, n, suf, piles, dp);
    }
};