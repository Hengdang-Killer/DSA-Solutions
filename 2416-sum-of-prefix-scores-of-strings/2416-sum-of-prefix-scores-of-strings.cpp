struct node
{
    node *nxt[26];
    int cnt;
    node()
    {
        for (int i = 0; i < 26; i++)
            nxt[i] = NULL;
        cnt = 0;
    }
};

node *root;

void insert_trie(string &s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - 'a';
        if (cur->nxt[imap] == NULL)
            cur->nxt[imap] = new node();
        cur->nxt[imap]->cnt++;
        cur = cur->nxt[imap];
    }
}

int search_trie(string &s)
{
    node *cur = root;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - 'a';
        ans += cur->nxt[imap]->cnt;
        cur = cur->nxt[imap];
    }
    return ans;
}

class Solution 
{
public:
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        root = new node();
        int n = words.size();
        for (int i = 0; i < n; i++) 
            insert_trie(words[i]);
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            ans[i] = search_trie(words[i]);
        return ans;   
    }
};