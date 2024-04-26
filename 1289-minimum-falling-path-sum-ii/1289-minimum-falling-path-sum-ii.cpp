class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = grid.size();
        vector<int> prev(n), cur(n);
        for(int j = 0; j < n; j++) 
            prev[j] = grid[0][j];
        for(int i = 1; i < n; ++i) 
        {
            for(int j = 0; j < n; j++) 
            {
                int temp = INT_MAX;
                for(int k = 0; k < n; k++) 
                {
                    if(k != j)
                        temp = min(temp, grid[i][j] + prev[k]);
                }
                cur[j] = temp;
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};