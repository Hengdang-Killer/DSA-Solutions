class Solution 
{
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int>  dy = {0, 0, -1, 1};
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[i][j] = 1;
        if(grid[i][j] == 0)
            return 0;
        int sum = 0;
        for(int k = 0; k < 4; k++)
        {
            int r = i + dx[k], c = j + dy[k];
            if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
                continue;
            if(!vis[r][c])
                sum = max(sum, dfs(r, c, grid, vis));
        }
        vis[i][j] = 0;
        return grid[i][j] + sum;
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j])
                    vis[i][j] = 1;
                else if(!vis[i][j])
                   ans = max(ans, dfs(i, j, grid, vis)); 
            }
        }
        return ans;
    }
};