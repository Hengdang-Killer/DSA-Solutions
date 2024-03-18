class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=1;
        int y=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=y){y=min(y,points[i][1]);continue;}
            count++;
            y=points[i][1];
        }
        return count;
        
    }
};