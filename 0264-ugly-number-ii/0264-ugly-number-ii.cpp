class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> dp(n);
        dp[0] = 1;
        int idxOf2 = 0, idxOf3 = 0, idxOf5 = 0;
        int nxtOf2 = 2, nxtOf3 = 3, nxtOf5 = 5;
        for (int i = 1; i < n; i++) 
        {
            int nxt = min(nxtOf2, min(nxtOf3, nxtOf5));
            dp[i] = nxt;
            if (nxt == nxtOf2) 
                nxtOf2 = dp[++idxOf2] * 2;
            if (nxt == nxtOf3)
                nxtOf3 = dp[++idxOf3] * 3;
            if (nxt == nxtOf5)
                nxtOf5 = dp[++idxOf5] * 5;
        }
        return dp[n - 1];
    }
};