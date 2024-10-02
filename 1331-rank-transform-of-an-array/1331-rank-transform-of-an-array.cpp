class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        map<int, vector<int>> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].push_back(i);
        }
        int cnt = 1;
        for(auto itr : mp)
        {
            for(auto itr2 : itr.second)
            {
                arr[itr2] = cnt;
            }
            cnt++;
        }
        return arr;
    }
};