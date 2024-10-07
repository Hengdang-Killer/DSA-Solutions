class Solution 
{
public:
    int minLength(string &s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i]=='B' && stk.size()>0 && stk.top()=='A')
                stk.pop();
            else if(s[i]=='D' && stk.size()>0 && stk.top()=='C')
                stk.pop();
            else
                stk.push(s[i]);
        }
        return stk.size();
    }
};