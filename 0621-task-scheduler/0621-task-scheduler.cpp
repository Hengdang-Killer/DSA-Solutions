class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(26, 0);
        int mx = 0;
        for(char &itr : tasks)
        {    
            freq[itr - 'A']++;
            mx = max(mx, freq[itr-'A'] - 1);
        }
        int idleCount = mx * (n + 1);
        for(int i = 0; i < 26; i++)
        {
            idleCount -= min(mx, freq[i]);
        }
        if(idleCount <= 0)
            return tasks.size();
        return tasks.size() + idleCount;
    }
};