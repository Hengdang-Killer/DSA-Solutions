class Solution 
{
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        long long ans = 0;
        vector<int> degree(n, 0);
        for(auto &itr : roads)
            degree[itr[0]]++, degree[itr[1]]++;
        sort(degree.rbegin(), degree.rend());
        for(auto &itr : degree)
            ans += (long long)(n--)*itr;
        return ans;
    }
};