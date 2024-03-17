class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(intervals.size() == 0)
            return {newInterval};
        int n = intervals.size();
        vector<vector<int>> ans;
        bool flag = 0;
        if(newInterval[1] < intervals[0][0])
        {
            ans.push_back(newInterval);
            flag = 1;
        }
        for(int i = 0; i < n; i++)
        {
            if(flag)
            {
                int sz = ans.size()-1;
                if(intervals[i][0] <= ans[sz][1])
                {
                    int l = min(intervals[i][0], ans[sz][0]);
                    int r = max(intervals[i][1], ans[sz][1]);
                    ans[sz][0] = l, ans[sz][1] = r;
                }
                else
                    ans.push_back(intervals[i]);
            }
            else
            {
                if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1])
                {
                    flag = 1;
                    int l = min(intervals[i][0], newInterval[0]);
                    int r = max(intervals[i][1], newInterval[1]);
                    ans.push_back({l,r});
                }
                else if(intervals[i][0] > newInterval[1])
                {
                    flag = 1;
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                }
                else
                    ans.push_back(intervals[i]);
            }
        }
        if(!flag)
            ans.push_back(newInterval);
        return ans;   
    }
};