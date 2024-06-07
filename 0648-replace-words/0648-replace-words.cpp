class Trie
{
public:
    bool isEnd;
    Trie *nxt[26];
    Trie() 
    {
        isEnd = 0;
        for(int i = 0; i < 26; i++)
            nxt[i] = NULL;
    }
};

class Solution 
{
private:
    Trie *root = new Trie();
    void insert(string &s)
    {
        int n = s.size();
        Trie *itr = root;
        for(int i = 0; i < n; i++)
        {
            if(!itr->nxt[s[i] - 'a'])
                itr->nxt[s[i]-'a'] = new Trie();
            itr = itr->nxt[s[i] - 'a'];
        }
        itr->isEnd = 1;
    }
    void search(string &s, string &ans)
    {
        int n = s.size();
        Trie *itr = root;
        for(int i = 0; i < n; i++)
        {
            if(!itr->nxt[s[i] - 'a'])
            {
                if(itr->isEnd)
                    return;
                while(i < n)
                {
                    ans.push_back(s[i]);
                    i++;
                }
                return;
            }
            ans.push_back(s[i]);
            itr = itr->nxt[s[i] - 'a'];
            if(itr->isEnd)
                return;
        }
        return;
    }
public:
    string replaceWords(vector<string>& dictionary, string &s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for(auto &itr : dictionary)
        {
            insert(itr);
        }
        string ans = "", temp = "";
        int i = 0, n = s.size();
        while(i < n)
        {
            if(s[i] == ' ')
                search(temp, ans), ans.push_back(' '), temp = "";
            else
                temp.push_back(s[i]);
            i++;
        }
        search(temp, ans);
        return ans;
    }
};