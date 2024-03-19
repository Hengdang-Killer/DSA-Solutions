class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> freq(26, 0);
        int mx = 0;
        for(char &itr : tasks)
        {    
            freq[itr - 'A']++;
            mx = max(mx, freq[itr-'A'] - 1);
        }
        int idleCount = mx * n;
        for(int i = 0; i < 26; i++)
        {
            idleCount -= min(mx, freq[i]);
        }
        idleCount += mx;
        if(idleCount <= 0)
            return tasks.size();
        return tasks.size() + idleCount;
    }
};