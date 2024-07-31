class Solution 
{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        int n = books.size();
        vector<int> dp(n+1, 0);
        dp[1] = books[0][1];
        for(int i = 2; i <= n; i++)
        {
            int widthLeft = shelfWidth - books[i-1][0];
            int mx = books[i-1][1];
            dp[i] = dp[i-1] + mx; // notTake
            int j = i - 1;
            while (j > 0 && widthLeft >= books[j-1][0]) 
            {
                widthLeft -= books[j-1][0];
                mx = max(mx, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + mx);
                j--;
            }
        }
        return dp[n];
    }
};
