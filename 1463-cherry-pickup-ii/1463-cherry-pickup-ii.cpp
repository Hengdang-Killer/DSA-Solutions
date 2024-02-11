class Solution 
{
private:
    int n, m;
    int dp[70][70][70];
    int recursion(int i, int j1, int j2, vector<vector<int>>& grid)
    {
        if(i >= n)
            return 0;
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int move = 0;
        for(int p = -1; p <= 1; p++)
        {
            for(int q = -1; q <= 1; q++)
            {
                if(j1 + p >= 0 && j1 + p < m && j2 + q >= 0 && j2 + q < m)
                {
                    move = max(move, recursion(i+1, j1 + p, j2 + q, grid));
                }
            }
        }
        dp[i][j1][j2] = move + grid[i][j1] + grid[i][j2];
        if(j1 == j2)
            dp[i][j1][j2] -= grid[i][j2];
        return dp[i][j1][j2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return recursion(0, 0, m-1, grid);
    }
};