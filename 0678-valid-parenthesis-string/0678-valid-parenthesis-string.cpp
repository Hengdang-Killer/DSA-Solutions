class Solution 
{
public:
    bool checkValidString(string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int openMin = 0, openMax = 0;
        for(auto &itr : s)
        {
            if(itr == '(')
                openMin++, openMax++;
            else if(itr == ')')
                openMin--, openMax--;
            else
                openMin--, openMax++;
            if(openMax < 0)
                return false;
            if(openMin < 0)
                openMin = 0;
        }
        if(openMin == 0)
            return true;
        return false;
    }
};