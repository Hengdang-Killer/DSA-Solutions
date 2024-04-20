class Solution 
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> ans;
        int cnt = 1;
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j] == 1)
                {
                    int par = -1;
                    if(i-1 >= 0 && land[i-1][j])
                        par = land[i-1][j];
                    if(par == -1 && j-1 >= 0 && land[i][j-1])
                        par = land[i][j-1];
                    if(par == -1)
                        ans.push_back({i, j, i, j}), land[i][j] = cnt++;
                    else
                    {
                        ans[par-1][0] = min(ans[par-1][0], i);
                        ans[par-1][1] = min(ans[par-1][1], j);
                        ans[par-1][2] = max(ans[par-1][2], i);
                        ans[par-1][3] = max(ans[par-1][3], j);
                        land[i][j] = par;
                    }
                }
            }
        }
        return ans;
    }
};