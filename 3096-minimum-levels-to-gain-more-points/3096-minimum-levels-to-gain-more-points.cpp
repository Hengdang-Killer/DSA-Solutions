class Solution 
{
public:
    int minimumLevels(vector<int>& possible) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int suf = 0, pre = 0, n = possible.size();
        for(int i = 0; i < n; i++)
            suf += (possible[i] == 1) ? 1 : -1;
        for(int i = 0; i < n-1 ; i++)
        {
            if(possible[i])
                pre += 1, suf -= 1;
            else
                pre -= 1, suf += 1;
            if(pre > suf)
                return i+1;
        }
        return -1;
    }
};