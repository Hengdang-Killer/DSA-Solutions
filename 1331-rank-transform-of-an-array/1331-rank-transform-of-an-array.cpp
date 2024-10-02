class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int> ans(arr.size());
        int cnt = 1;
        for(auto itr : mp)
        {
            for(auto itr2 : itr.second)
            {
                ans[itr2] = cnt;
            }
            cnt++;
        }
        return ans;
    }
};