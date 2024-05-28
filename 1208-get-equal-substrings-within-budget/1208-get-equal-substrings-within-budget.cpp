class Solution 
{
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.size();
        vector<int> cost(n);
        for(int i = 0; i < n; i++)
            cost[i] = abs(s[i] - t[i]);
        int l = 0, r = 0, cur = 0, ans = 0;
        while(r < n)
        {
            cur += cost[r];
            while(cur > maxCost)
            {
                cur -= cost[l];
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};