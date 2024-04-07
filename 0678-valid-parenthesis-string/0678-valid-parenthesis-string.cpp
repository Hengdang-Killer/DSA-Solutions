class Solution 
{
private:
    int recursion(int i, int brkt, string &s, vector<vector<int>> &dp)
    {
        if(i >= s.size())
        {
            if(brkt == 0)
                return 1;
            return 0;
        }
        if(dp[i][brkt] != -1)
            return dp[i][brkt];
        if(s[i] == '(')
            return dp[i][brkt] = recursion(i+1, brkt + 1, s, dp);
        if(s[i] == ')')
        {
            if(brkt > 0)
                return dp[i][brkt] = recursion(i+1, brkt-1, s, dp); 
            return dp[i][brkt] = 0;
        }
        int notTake = 0, open = 0, close = 0;
        if(brkt != 0)
            close = recursion(i+1, brkt - 1, s, dp);
        open = recursion(i+1, brkt+1, s, dp);
        notTake = recursion(i+1, brkt, s, dp);
        return dp[i][brkt] = notTake | open | close;
    }
public:
    bool checkValidString(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> dp(s.size(), vector<int> (s.size() + 1, -1));
        return recursion(0, 0, s, dp);
    }
};