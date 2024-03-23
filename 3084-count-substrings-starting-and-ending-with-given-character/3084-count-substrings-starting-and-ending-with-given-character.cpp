class Solution 
{
public:
    long long countSubstrings(string s, char c) 
    {
        long long cnt = 0;
        for(char &itr : s)
        {
            if(itr == c)
                cnt++;
        }
        long long ans = (cnt*(cnt+1))/2;
        return ans;
    }
};