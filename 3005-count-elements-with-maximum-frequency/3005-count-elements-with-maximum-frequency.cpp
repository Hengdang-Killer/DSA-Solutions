class Solution 
{
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        vector<int> freq(101, 0);
        int mx = 0, cnt = 0;
        for(auto &itr : nums)
        {
            freq[itr]++;
            mx = max(mx, freq[itr]);
        }
        for(auto &itr : freq)
        {
            if(mx == itr)
                cnt++;
        }
        return mx*cnt;
    }
};