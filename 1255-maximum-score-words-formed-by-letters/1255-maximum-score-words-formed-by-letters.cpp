class Solution 
{
private:
    map<int, map<string, int>> dp;
    int recursion(int i, string j, vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        if(i >= words.size())
            return 0;
        if(dp[i].find(j) != dp[i].end())
            return dp[i][j];
        int notTake = recursion(i+1, j, words, letters, score);
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
            take += recursion(i+1, temp, words, letters, score);
        else
            take = recursion(i+1, j, words, letters, score);
        return dp[i][j] = max(take, notTake);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        dp.clear();
        string bitmask = "";
        for(int i = 0; i < letters.size(); i++)
        {
            bitmask.push_back('0');
        }
        int ans = recursion(0, bitmask, words, letters, score);
        /*
        for(auto itr : dp)
        {
            cout << itr.first << ":-\n";
            for(auto itr2 : itr.second)
            {
                cout << itr2.first << " " << itr2.second << '\n';
            }
            cout<<'\n';
        }
        */
        return ans;
    }
};