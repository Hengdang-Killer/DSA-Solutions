class Solution 
{
public:
    string makeGood(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<char> stk;
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(!stk.empty())
            {
                if(stk.top() <= 'Z' && s[i] > 'Z' && stk.top()-'A' == s[i]-'a')
                    stk.pop();
                else if(stk.top() > 'Z' && s[i] <= 'Z' && stk.top()-'a' == s[i]-'A')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
            else
                stk.push(s[i]);
        }
        s = "";
        while(!stk.empty())
        {
            s.push_back(stk.top());
            stk.pop();
        }
        return s;
    }
};