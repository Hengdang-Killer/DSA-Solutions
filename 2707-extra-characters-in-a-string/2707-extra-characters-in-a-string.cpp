
struct Trie
{
    Trie *next[26];
    bool isEnd;
    Trie()
    {
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        isEnd = false;
    }
};

Trie *root;

void insertTrie(string &s)
{
    Trie *node = root;
    for(char &itr : s)
    {
        if(node->next[itr - 'a'] == NULL)
            node->next[itr - 'a'] = new Trie();
        node = node->next[itr - 'a'];
    }
    node->isEnd = true;
}

class Solution 
{
private:
    int recursion(int i, int &n, string &s, vector<int> &dp)
    {
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int notTake = 1 + recursion(i + 1, n, s, dp);
        int take = 1e9;
        Trie* node = root;
        for(int j = i; j < n; j++)
        {
            if(node->next[s[j]-'a'] == NULL)
                break;
            if(node->next[s[j]-'a']->isEnd)
                take = min(take, recursion(j+1, n, s, dp));
            node = node->next[s[j]-'a'];
        }
        return dp[i] = min(take, notTake);
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        int n = s.length();
        root = new Trie();
        vector<int> dp(n, -1);
        for(string &itr : dictionary)
        {
            insertTrie(itr);
        }
        return recursion(0, n, s, dp);
    }
};