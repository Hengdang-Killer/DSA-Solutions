class Solution 
{
public:
    string convertDateToBinary(string &date) 
    {
        string year = "", month = "", day = "";
        for(int i = 0; i < 4; i++)
            year.push_back(date[i]);
        for(int i = 5; i < 7; i++)
            month.push_back(date[i]);
        for(int i = 8; i < 10; i++)
            day.push_back(date[i]);
        string ans = "";
        int yr = stoi(year), mnth = stoi(month), dy = stoi(day);
        bool ok = 0;
        for(int i = 30; i >= 0; i--)
        {
            if((yr >> i)&1)
                ok = 1, ans.push_back('1');
            else if(ok)
                ans.push_back('0');
        }
        ans.push_back('-'), ok = 0;
        for(int i = 30; i >= 0; i--)
        {
            if((mnth >> i)&1)
                ok = 1, ans.push_back('1');
            else if(ok)
                ans.push_back('0');
        }
        ans.push_back('-'), ok = 0;
        for(int i = 30; i >= 0; i--)
        {
            if((dy >> i)&1)
                ok = 1, ans.push_back('1');
            else if(ok)
                ans.push_back('0');
        }
        return ans;
    }
    
};