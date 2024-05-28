class Solution 
{
public:
    vector<vector<int>> generate(int &n) 
    {
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i+1; j++)
            {
                if(j == 0 || j == i)
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
            }
        }
        return ans;
    }
};