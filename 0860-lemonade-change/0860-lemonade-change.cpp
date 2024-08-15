class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int cnt1 = 0, cnt2 = 0;
        for(auto &itr : bills)
        {
            if(itr == 5)
                cnt1++;
            else if(itr == 10)
            {
                if(cnt1 == 0)
                    return false;
                cnt1--, cnt2++;
            }
            else
            {
                if(cnt1 == 0)
                    return false;
                if(cnt2 == 0 && cnt1 < 3)
                    return false;
                if(cnt2 == 0)
                    cnt1 -= 3;
                else
                    cnt1--, cnt2--;
            }
        }
        return true;    
    }
};