class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(), points.end());
        vector<pair<int, int>> finalPoints;
        for(auto itr : points)
        {
            if(finalPoints.size())
            {
                int sz = finalPoints.size() - 1;
                if(finalPoints[sz].second >= itr[0])
                {
                    int l = max(finalPoints[sz].first, itr[0]);
                    int r = min(finalPoints[sz].second, itr[1]);
                    finalPoints[sz] = {l, r};
                }
                else
                    finalPoints.push_back({itr[0], itr[1]});
            }
            else
                finalPoints.push_back({itr[0], itr[1]});
        }
        return finalPoints.size();
    }
};