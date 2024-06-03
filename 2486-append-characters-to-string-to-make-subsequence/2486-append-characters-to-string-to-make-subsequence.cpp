class Solution 
{
public:
    int appendCharacters(string &s, string &t) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.size(), m = t.size(), i = 0, j = 0;
        while(i < n && j < m)
        {
            if(s[i] == t[j])
                i++, j++;
            else
                i++;
        }
        if(j < m)
            return m - j;
        return 0;
    }
};