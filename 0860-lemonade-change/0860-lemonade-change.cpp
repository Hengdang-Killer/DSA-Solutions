class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int cnt1 = 0, cnt2 = 0;
        for(auto &itr : bills)
        {
            if(itr == 5)
                cnt1++;
            else
            {
                if(cnt1 == 0)
                    return false;
                if(itr == 10)
                    cnt1--, cnt2++;
                else
                {
                    if(cnt2 == 0 && cnt1 < 3)
                        return false;
                    if(cnt2 == 0)
                        cnt1 -= 3;
                    else
                        cnt1--, cnt2--;
                }
            }
        }
        return true;    
    }
};