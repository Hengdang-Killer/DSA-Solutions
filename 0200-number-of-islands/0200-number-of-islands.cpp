class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);    
        int ans = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty())
                    {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        if(x -1 >= 0 && !vis[x-1][y] && grid[x-1][y] == '1')
                            q.push({x-1, y}), vis[x-1][y]++;
                        if(y -1 >= 0 && !vis[x][y-1] && grid[x][y-1] == '1')
                            q.push({x, y-1}), vis[x][y-1]++;
                        if(x + 1 < grid.size() && !vis[x+1][y] && grid[x+1][y] == '1')
                            q.push({x+1, y}), vis[x+1][y]++;
                        if(y + 1 < grid[0].size() && !vis[x][y+1] && grid[x][y+1] == '1')
                            q.push({x, y+1}), vis[x][y+1]++;
                    }
                }
            }
        }
        return ans;
    }
};