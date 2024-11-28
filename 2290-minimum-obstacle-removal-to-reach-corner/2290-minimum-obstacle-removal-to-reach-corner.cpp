class Solution 
{
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        deque<vector<int>> dq;
        dq.push_front({0, 0, 0});
        while(!dq.empty())
        {
            int curRow = dq.front()[1], curCol = dq.front()[2], obstacle = dq.front()[0];
            dq.pop_front();
            for(auto &itr : dir)
            {
                int newRow = curRow + itr[0], newCol = curCol + itr[1];
                if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || dp[newRow][newCol] != 1e9)
                    continue;
                if (grid[newRow][newCol] == 1) 
                {
                    dp[newRow][newCol] = obstacle + 1;
                    dq.push_back({obstacle + 1, newRow, newCol});
                } 
                else 
                {
                    dp[newRow][newCol] = obstacle;
                    dq.push_front({obstacle, newRow, newCol});
                }
            }
        }   
        return dp[n-1][m-1];
    }
};