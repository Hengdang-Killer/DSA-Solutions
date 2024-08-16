class Solution 
{
public:
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int mn = arrays[0][0], mx = arrays[0].back();
        int ans = 0;
        for (int i = 1; i < arrays.size(); i++) 
        {
            ans = max({ans, abs(arrays[i].back() - mn), abs(mx - arrays[i][0])});
            mn = min(mn, arrays[i][0]);
            mx = max(mx, arrays[i].back());
        }
        return ans;
    }
};