class Solution 
{
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l = 0, r = 0, cur = 0, ans = 0;
        while(r < s.size())
        {
            cur += abs(s[r] - t[r]);
            while(cur > maxCost)
            {
                cur -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};