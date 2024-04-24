class Solution 
{
public:
    vector<int> ans;
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ans.push_back(0);
        ans.push_back(1);
        ans.push_back(1);
        int sz = 2;
        for(int i = 3; i <= 37; i++)
        {
            ans.push_back(ans[sz]+ans[sz-1]+ans[sz-2]);
            sz++;
        }
    }
    int tribonacci(int n) 
    {
        return ans[n];
    }
};