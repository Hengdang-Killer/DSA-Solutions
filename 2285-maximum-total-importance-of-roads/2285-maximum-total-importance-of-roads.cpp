class Solution 
{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        long long ans = 0;
        vector<pair<int, int>> degree(n);
        vector<int> numbering(n);
        for(int i = 0; i < n; i++)
            degree[i].second = i, degree[i].first = 0;
        for(auto &itr : roads)
            degree[itr[0]].first++, degree[itr[1]].first++;
        sort(degree.rbegin(), degree.rend());
        for(auto &itr : degree)
            numbering[itr.second] = n--;
        for(auto &itr : roads)
            ans += numbering[itr[0]] + numbering[itr[1]];
        return ans;
    }
};