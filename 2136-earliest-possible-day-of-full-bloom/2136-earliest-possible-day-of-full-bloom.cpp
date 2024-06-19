// grow time can overlap
// plant time cannot overlap
// so that means most overlapping growth would give us minimum time

class Solution 
{
private:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first > b.first;
    }
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int, int>> v;
        for(int i = 0; i < plantTime.size(); i++)
            v.push_back({growTime[i] + 1, plantTime[i]});
        sort(v.begin(), v.end(), comp);
        int prev = 0, ans = 0;
        for(int i = 0; i < plantTime.size(); i++)
        {
            ans = max(ans, prev + v[i].first + v[i].second);
            prev += v[i].second;
        }
        return ans - 1;
    }
};