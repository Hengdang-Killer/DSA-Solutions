class Solution 
{
public:
    int minimumPushes(string &word) 
    {
        vector<int> freq(26, 0);
        for(auto &itr : word)
            freq[itr - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int ans = 0, cnt = 0, val = 1;
        for(int i = 0; i < 26; i++)
        {
            if(freq[i] == 0)
                break;
            cnt++;
            ans += val*freq[i];
            if(cnt == 8)
                val++, cnt = 0;
        }
        return ans;
    }
};