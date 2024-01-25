// Recursion + Memoisation
// T.C. : O(n*m) , S.C. : O(n*m) + O(n) 
/*class Solution 
{
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i == s1.length() || j == s2.length()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = 1 + f(i+1, j+1, s1, s2, dp);
        return dp[i][j] = max(f(i+1, j, s1, s2, dp), f(i, j+1, s1, s2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        ios_base::sync_with_stdio(0);   
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        return f(0, 0, text1, text2, dp);
    }
};*/

// Tabulation
// T.C. : O(n*m) , S.C. : O(n*m) 
/*class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        ios_base::sync_with_stdio(0);   
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        for(int i = text1.size() - 1; i >= 0; i--)
        {
            for(int j = text2.size() - 1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};*/

// Space Optimisation
// T.C. : O(n*m) , S.C. : O(m) 
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        ios_base::sync_with_stdio(0);   
        vector<int> prev(text2.size() + 1, 0), cur(text2.size() + 1, 0);
        for(int i = text1.size() - 1; i >= 0; i--)
        {
            for(int j = text2.size() - 1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                    cur[j] = 1 + prev[j+1];
                else
                    cur[j] = max(prev[j], cur[j+1]);
            }
            prev= cur;
        }
        return prev[0];
    }
};