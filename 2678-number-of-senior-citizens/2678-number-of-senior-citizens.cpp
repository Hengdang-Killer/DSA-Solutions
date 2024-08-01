class Solution 
{
public:
    int countSeniors(vector<string>& details) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for(auto &itr : details)
        {
            int age = (itr[11] - '0')*10 + (itr[12] - '0');
            if(age > 60)
                ans++;
        }    
        return ans;
    }
};