class Solution 
{
public:
    bool isSubstringPresent(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = s.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = n-1; j >= 1; j--)
            {
                if(s[j] == s[i] && s[j-1] == s[i+1])
                    return true;
            }
        }
        return false;
    }
};