class Solution 
{
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    int cnt = 0;
                    if(i-1 >= 0 && grid[i-1][j] == 1)
                        cnt++;
                    if(i+1 < n && grid[i+1][j] == 1)
                        cnt++;
                    if(j-1 >= 0 && grid[i][j-1] == 1)
                        cnt++;
                    if(j+1 < m && grid[i][j+1] == 1)
                        cnt++;
                    ans += 4 - cnt;
                }
            }
        }
        return ans;
    }
};