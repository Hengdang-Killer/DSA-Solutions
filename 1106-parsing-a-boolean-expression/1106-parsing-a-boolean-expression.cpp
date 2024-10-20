class Solution 
{
    char evaluate(char &op, vector<char> &vals)
    {
        if(op == '!')
            return (vals[0] == 't') ? 'f' : 't';
        if(op == '&')
        {
            for(auto &itr : vals)
            {
                if(itr == 'f')
                    return 'f';
            }
            return 't';
        }
        if(op == '|')
        {
            for(auto &itr : vals)
            {
                if(itr == 't')
                    return 't';
            }
        }
        return 'f';
    }
public:
    bool parseBoolExpr(string &expression) 
    {
        stack<char> stk;    
        for(auto itr : expression)
        {
            if(itr == ')')
            {
                vector<char> vals;
                while(stk.top() != '(')
                {
                    vals.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                char result = evaluate(op, vals);
                stk.push(result);
            }
            else if(itr != ',')
                stk.push(itr);
        }
        return stk.top() == 't';
    }
};