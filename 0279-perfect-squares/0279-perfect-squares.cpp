/* Recursion + Memoisation
class Solution 
{
private:
    int recursion(int n, vector<int> &dp)
    {
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
            return dp[n];
        dp[n] = 1e8;
        for(int i = 1; i*i <= n ; i++)
        {
            if(i*i <= n)
            {
                dp[n] = min(dp[n], 1 + recursion(n-i*i, dp));
            }
        }
        return dp[n];
    }
public:
    int numSquares(int n) 
    {
        ios_base::sync_with_stdio(0);
        vector<int> dp(n+1,-1);
        return recursion(n, dp);
    }
};
*/
/* Tabulation 
class Solution 
{
public:
    int numSquares(int n) 
    {
        ios_base::sync_with_stdio(0);
        vector<int> dp(n+1, 0);
        for(int j = 1; j <= n; j++)
        {
            dp[j] = 1e8;
            for(int i = 1; i*i <= j ; i++)
            {
                if(i*i <= j)
                {
                    dp[j] = min(dp[j], 1 + dp[j-i*i]);
                }
            }
        }
        return dp[n];
    }
};
*/
class Solution 
{
public:
    int numSquares(int n) 
    {
        ios_base::sync_with_stdio(0);
        if(ceil(sqrt(n)) == floor(sqrt(n)))
            return 1;
        while(n%4 == 0)   //Remove 4^a term
            n/=4;
        if(n%8 == 7)      //check if the no now is in the form of (8b + 7)
            return 4;
        for(int i = 1; i*i <= n; i++)
        {
            int base = sqrt(n-i*i);
            if(base*base==(n-i*i))
                return 2;
        }
        return 3;
    }
};