class Solution 
{
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(n == 1)
            return 1;
        vector<int> v(n, 0);
        for(auto &itr : trust)
        {
            v[itr[0]-1] = -1001, v[itr[1] - 1]++;
        }
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(v[i] > 0)
            {
                if(v[i] == n-1)
                    ans = i+1;
                break;
            }
        }
        return ans;
    }
};