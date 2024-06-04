class Solution 
{
public:
    int longestPalindrome(string &s) 
    {
        bool odd = 0;
        int ans = 0;
        vector<int> freq1(26, 0), freq2(26, 0);
        for(auto &itr : s)
        {
            if(itr <= 'z' && itr >= 'a')
                freq1[itr-'a']++;
            else
                freq2[itr-'A']++;
        }
        for(auto &itr : freq1)
        {
            if(itr%2)
                odd = 1, ans += itr-1;
            else
                ans += itr;
        }
        for(auto &itr : freq2)
        {
            if(itr%2)
                odd = 1, ans += itr - 1;
            else
                ans += itr;
        }
        if(odd)
            ans++;
        return ans;
    }
};