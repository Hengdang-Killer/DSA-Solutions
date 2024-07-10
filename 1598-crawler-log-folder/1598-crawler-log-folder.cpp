class Solution 
{
public:
    int minOperations(vector<string>& logs) 
    {
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