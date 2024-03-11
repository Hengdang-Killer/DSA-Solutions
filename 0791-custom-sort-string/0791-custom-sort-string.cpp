class Solution 
{
public:
    string customSortString(string order, string s) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(26, 0);
        for(auto &itr : s)
            freq[itr-'a']++;
        s = "";
        for(auto &itr : order)
        {
            while(freq[itr-'a'] > 0)
               s.push_back(itr), freq[itr-'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            while(freq[i] > 0)
               s.push_back(i+'a'), freq[i]--;
        }
        return s;
    }
};