class Solution 
{
public:
    int minimumPushes(string &word) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
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