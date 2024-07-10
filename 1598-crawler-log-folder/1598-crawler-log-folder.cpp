class Solution 
{
public:
    int minOperations(vector<string>& logs) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for(auto &itr : logs)
        {
            if(itr == "../")
                ans = max(ans-1, 0);
            else if(itr == "./")
                continue;
            else
                ans++;
        }
        return ans;
    }
};