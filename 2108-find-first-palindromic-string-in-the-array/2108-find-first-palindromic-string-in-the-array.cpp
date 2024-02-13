class Solution 
{
public:
    string firstPalindrome(vector<string>& words) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for(auto &itr : words)
        {
            int i = 0, j = itr.size()-1;
            bool flag = 1;
            while(i < j)
            {
                if(itr[i] != itr[j])
                {
                    flag = 0;
                    break;
                }
                i++, j--;
            }
            if(flag)
                return itr;
        }
        return "";
    }
};