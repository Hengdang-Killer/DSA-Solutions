class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        bool ok = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                    ok = 1;
                    break;
                }
            }
            if(ok)
                break;
        }
        int ans = 0;
        while(!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            int cnt = 0;
            if(i-1 >= 0 && grid[i-1][j] == 1)
            {
                cnt++;
                if(!vis[i-1][j])
                    q.push({i-1, j}), vis[i-1][j] = 1;
            }
            if(i+1 < n && grid[i+1][j] == 1)
            {
                cnt++;
                if(!vis[i+1][j])
                    q.push({i+1, j}), vis[i+1][j] = 1;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1)
            {
                cnt++;
                if(!vis[i][j-1])
                    q.push({i, j-1}), vis[i][j-1] = 1;
            }
            if(j+1 < m && grid[i][j+1] == 1)
            {            
                cnt++;
                if(!vis[i][j+1])
                    q.push({i, j+1}), vis[i][j+1] = 1;
            }
            ans += 4 - cnt;
        }
        return ans;
    }
};