class Solution 
{
private:
    vector<string> recursion(int i, string &s, unordered_set<string> &wordDict, unordered_map<int, vector<string>> &dp)
    {
        if (dp.find(i) != dp.end())
            return dp[i];
        vector<string> ans;
        if (i == s.length())
            ans.push_back("");
        for (int j = i + 1; j <= s.length(); j++) 
        {
            string prefix = s.substr(i, j - i);
            if (wordDict.find(prefix) != wordDict.end()) 
            {
                vector<string> suffixes = recursion(j, s, wordDict, dp);
                for (string &suffix : suffixes)
                    ans.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
            }
        }
        return dp[i] = ans;
    }
public:
    vector<string> wordBreak(string &s, vector<string>& wordDict) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, vector<string>> dp;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return recursion(0, s, dict, dp);
    }
};