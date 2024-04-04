class Solution 
{
public:
    int maxDepth(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0, cur = 0;
        for (char &ch : s) 
        {
            if (ch == '(') 
            {
                cur++;
                if (ans < cur)
                    ans = cur;
            } 
            else if (ch == ')') 
                cur--;
        }
        return ans;   
    }
};