class Solution 
{
public:
    long long countSubstrings(string s, char c) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int cnt = 0;
        for(char &itr : s)
        {
            if(itr == c)
                cnt++;
        }
        long long ans = ((long long)cnt*(cnt+1))/2;
        return ans;
    }
};