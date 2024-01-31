class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& v) 
    {
        int n = v.size();
        vector<int> ans(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n-1; i++)
        {
            if(v[i] < v[i+1])
                ans[i]++;
            else
                pq.push({v[i], i});
            while(!pq.empty() && pq.top().first < v[i])
            {
                ans[pq.top().second] = i - pq.top().second;
                pq.pop();
            }
        }
        while(!pq.empty() && pq.top().first < v[n-1])
        {
            ans[pq.top().second] = n - 1 - pq.top().second;
            pq.pop();
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();