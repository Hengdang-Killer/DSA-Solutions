class Solution 
{
private:
    int recursion(int i, string j, vector<string>& words, vector<char>& letters, vector<int>& score, map<int, map<string, int>> &dp)
    {
        if(i >= words.size())
            return 0;
        if(dp[i].find(j) != dp[i].end())
            return dp[i][j];
        int notTake = recursion(i+1, j, words, letters, score, dp);
        int take = 0, itr = 0;
        string temp = j;
        while(itr < words[i].size())
        {
            bool flag = 0;
            for(int k = 0; k < letters.size(); k++)
            {
                if(letters[k] == words[i][itr] && temp[k] == '0')
                {
                    temp[k] = '1', take += score[letters[k]-'a'], flag = 1;
                    break;
                }
            }
            if(!flag)
                break;
            itr++;
        }
        if(itr == words[i].size())
            take += recursion(i+1, temp, words, letters, score, dp);
        else
            take = recursion(i+1, j, words, letters, score, dp);
        return dp[i][j] = max(take, notTake);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        map<int, map<string, int>> dp;
        string bitmask = "";
        for(int i = 0; i < letters.size(); i++)
        {
            bitmask.push_back('0');
        }
        return recursion(0, bitmask, words, letters, score, dp);
    }
};