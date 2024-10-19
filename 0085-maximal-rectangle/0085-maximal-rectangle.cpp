class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& mat) 
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> cols(n, vector<int> (m, 0));
        for(int j = 0; j < m; j++)
        {
            int cur = 0;
            for(int i = n-1; i >= 0; i--)
            {
                if(mat[i][j] == '1')
                    cur++;
                else
                    cur = 0;
                cols[i][j] = cur;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == '1')
                {
                    int x = 0, y = 1e5;
                    for(int k = j; k < m; k++)
                    {
                        if(mat[i][k] != '1')
                            break;
                        x++, y = min(y, cols[i][k]);
                        ans = max(ans, x*y);
                    }
                }
            }
        }
        return ans;
    }
};