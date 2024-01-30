class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> stk;
        for(auto itr : tokens)
        {
            if(itr == "+" || itr == "-" || itr == "*" || itr == "/")
            {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                if(itr == "+")
                    val2 += val1;
                else if(itr == "-")
                    val2 -= val1;
                else if(itr == "*")
                    val2 *= val1;
                else
                    val2 /= val1;
                stk.push(val2);
            }
            else
            {
                int sum = 0, cnt = 1;
                for(int i = itr.size() - 1; i >= 0; i--)
                {
                    if(i == 0 && itr[i] == '-')
                    {
                        sum = -sum;
                        continue;
                    }
                    sum += (itr[i] - '0')*cnt;
                    cnt *= 10;
                }
                stk.push(sum);
            }
        }
        return stk.top();
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();