struct node
{
    node *nxt[10];
    node()
    {
        for (int i = 0; i < 10; i++)
            nxt[i] = NULL;
    }
};

node *root;

void insert_trie(string &s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - '0';
        if (cur->nxt[imap] == NULL)
            cur->nxt[imap] = new node();
        cur = cur->nxt[imap];
    }
}

int search_trie(string &s)
{
    node *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int imap = s[i] - '0';
        if (cur->nxt[imap] == NULL)
            return i;
        cur = cur->nxt[imap];
    }
    return s.size();
}

class Solution 
{
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        root = new node();
        int ans = 0;
        for(auto itr : arr1)
        {
            string s = to_string(itr);
            insert_trie(s);
        }
        for(auto itr : arr2)
        {
            string s = to_string(itr);
            ans = max(ans, search_trie(s));
        }
        return ans;
    }
};