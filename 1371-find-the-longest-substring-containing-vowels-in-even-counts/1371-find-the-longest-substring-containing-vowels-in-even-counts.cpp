class Solution 
{
public:
    int findTheLongestSubstring(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int preXor = 0;
        int mp[26] = {0};
        mp['a' - 'a'] = 1, mp['e' - 'a'] = 2, mp['i' - 'a'] = 4, mp['o' - 'a'] = 8, mp['u' - 'a'] = 16;
        vector<int> idx(32, -1);
        int ans = 0, n = s.size();
        for (int i = 0; i < n; i++) 
        {
            preXor ^= mp[s[i] - 'a'];
            if (idx[preXor] == -1 && preXor != 0) 
                idx[preXor] = i;
            ans = max(ans, i - idx[preXor]);
        }
        return ans;
    }
};