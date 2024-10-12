class Solution 
{
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        int mn = INT_MAX, mx = INT_MIN;
        for(auto &itr : intervals)
            mn = min(mn, itr[0]), mx = max(mx, itr[1]);
        vector<int> points(mx-mn+2, 0);
        for(auto &itr : intervals)
            points[itr[0]-mn]++, points[itr[1]+1-mn]--;
        int cur = 0, ans = 0;
        for(int &itr : points)
        {
            cur += itr;
            ans = max(ans, cur);
        }
        return ans;
    }
};