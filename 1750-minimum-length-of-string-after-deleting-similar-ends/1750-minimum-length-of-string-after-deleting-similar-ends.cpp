class Solution 
{
public:
    int minimumLength(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) 
        {
            char ch = s[l];
            while (l <= r && s[l] == ch) 
                l++;
            while (r >= l && s[r] == ch)
                r--;
        }
        return r - l + 1;    
    }
};