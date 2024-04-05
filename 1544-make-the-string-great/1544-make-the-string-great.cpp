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
            char ch = s[i];
            if(!stk.empty())
            {
                char test = stk.top();
                if(test <= 'Z' && ch > 'Z' && test-'A' == ch-'a')
                    stk.pop();
                else if(test > 'Z' && ch <= 'Z' && test-'a' == ch-'A')
                    stk.pop();
                else
                    stk.push(ch);
            }
            else
                stk.push(ch);
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