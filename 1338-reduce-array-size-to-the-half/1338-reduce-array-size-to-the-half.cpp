class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        for(auto &itr : arr)
            mp[itr]++;
        priority_queue<int> pq;
        for(auto itr : mp)
            pq.push(itr.second);
        int n = arr.size(), ans = 0;
        while(!pq.empty())
        {
            n -= pq.top();
            pq.pop();
            ans++;
            if(n <= arr.size()/2)
                return ans;
        }
        return arr.size();
    }
};