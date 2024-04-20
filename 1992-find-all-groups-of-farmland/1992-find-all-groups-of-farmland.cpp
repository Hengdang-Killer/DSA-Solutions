class Solution 
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> ans;
        for(int i = 0; i < land.size(); i++)
        {
            for(int j = 0; j < land[0].size(); j++)
            {
                if(land[i][j] == 1)
                {
                    int x = 300, y = 300, xx = 0, yy = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    land[i][j] = 0;
                    while(!q.empty())
                    {
                        int ax = q.front().first, ay = q.front().second;
                        q.pop();
                        x = min(x, ax), y = min(y, ay), xx = max(xx, ax), yy = max(yy, ay);
                        if(ax-1 >= 0 && land[ax-1][ay])
                            q.push({ax-1, ay}), land[ax-1][ay] = 0;
                        if(ax+1 < land.size() && land[ax+1][ay])
                            q.push({ax+1, ay}), land[ax+1][ay] = 0;
                        if(ay-1 >= 0 && land[ax][ay-1])
                            q.push({ax, ay-1}), land[ax][ay-1] = 0;
                        if(ay+1 < land[0].size() && land[ax][ay+1])
                            q.push({ax, ay+1}), land[ax][ay+1] = 0;
                    }
                    ans.push_back({x, y, xx, yy});
                }
            }
        }
        return ans;
    }
};