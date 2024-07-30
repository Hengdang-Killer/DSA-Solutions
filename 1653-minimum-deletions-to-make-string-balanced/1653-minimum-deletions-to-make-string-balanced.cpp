class Solution 
{
public:
    int minimumDeletions(string s) 
    {
        int n = s.size();
        int b_cnt = 0, cur = 0, nxt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
                nxt = cur, b_cnt++;
            else
                nxt = min(cur + 1, b_cnt);
            cur = nxt;
        }
        return cur;
    }
};