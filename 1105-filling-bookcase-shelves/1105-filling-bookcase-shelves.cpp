class Solution 
{
private:
    int recursion(int i, int widthLeft, int mx, int &n, int &shelfWidth, vector<vector<int>> &dp, vector<vector<int>>& books)
    {
        if(i >= n)
            return mx;
        if(dp[i][widthLeft] != -1)
            return dp[i][widthLeft];
        int take = 1e8, notTake = 1e8;
        if(books[i][0] <= widthLeft)
            take = recursion(i+1, widthLeft - books[i][0], max(mx, books[i][1]), n, shelfWidth, dp, books);
        notTake = mx + recursion(i+1, shelfWidth - books[i][0], books[i][1], n, shelfWidth, dp, books);
        return dp[i][widthLeft] = min(take, notTake);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int> (shelfWidth + 1, -1));
        return recursion(0, shelfWidth, 0, n, shelfWidth, dp, books);
    }
};