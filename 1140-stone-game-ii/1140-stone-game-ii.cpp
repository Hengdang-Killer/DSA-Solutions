class Solution 
{
private:
    int recursion(int i, int j, int state, int n, vector<int> &suf, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        if(i >= n)
            return 0;
        if(dp[i][j][state] != -1)
            return dp[i][j][state];
        int val = 0, sum = 0;
        for(int k = 1; k <= 2*j; k++)
        {
            if(i + k - 1 >= n)
                break;
            sum += piles[i + k - 1];
            int nxtM = max(k, j);
            int nxtState = (state == 0) ? 1 : 0;
            val = max(val, suf[i] - recursion(i + k, nxtM, nxtState, n, suf, piles, dp));
        }
        return dp[i][j][state] = val;
    }
public:
    int stoneGameII(vector<int>& piles) 
    {
        int n = piles.size();
        vector<int> suf(n, 0);
        for(int i = n-1; i >= 0; i--)
        {
            if(i != n-1)
                suf[i] += suf[i+1];
            suf[i] += piles[i];
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (1e3, vector<int>(2, -1)));
        return recursion(0, 1, 0, n, suf, piles, dp);
    }
};