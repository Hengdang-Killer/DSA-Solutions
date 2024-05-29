class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(i == 0)
                ans.push_back(intervals[i]);
            else
            {
                if(ans[ans.size() - 1][1] >= intervals[i][0])
                    ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
                else
                    ans.push_back(intervals[i]);
            }
        }
        return ans;   
    }
};