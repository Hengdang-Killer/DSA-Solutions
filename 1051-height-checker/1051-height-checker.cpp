class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(101, 0);
        for(auto &itr : heights)
            freq[itr]++;
        int i = 0, j = 0, ans = 0;
        while(j < heights.size())
        {
            while(i <= 100 && freq[i] == 0)
                i++;
            freq[i]--;
            if(i != heights[j])
                ans++;
            j++;
        }
        return ans;
    }
};