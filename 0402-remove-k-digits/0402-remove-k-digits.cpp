class Solution 
{
public:
    string removeKdigits(string &num, int k) 
    {
        if(k >= num.size())
            return "0";
        stack<char> stk;        
        for (char &digit : num) 
        {
            while (!stk.empty() && k > 0 && stk.top() > digit) 
                stk.pop(), k--;
            stk.push(digit);
        }
        while (k > 0 && !stk.empty()) 
            stk.pop(), k--;
        num = "";
        while (!stk.empty()) 
        {
            num.push_back(stk.top());
            stk.pop();
        }
        reverse(num.begin(), num.end());
        size_t pos = num.find_first_not_of('0');
        num = (pos == std::string::npos) ? "0" : num.substr(pos);
        return num;
    }
};