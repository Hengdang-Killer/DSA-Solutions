class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int prev = 0, cur = 0;
        for(char &itr : s)
        {
            if(itr == ' ')
            {
                if(cur != 0)
                    prev = cur;
                cur = 0;
            }
            else
                cur++;
        }
        if(cur == 0)
            return prev;
        return cur;
    }
};