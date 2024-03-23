class Solution 
{
public:
    int minimumDeletions(string word, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(26, 0);
        int cnt = 0, ans = word.size();
        for(auto &itr: word) 
            freq[itr - 'a']++;            
        sort(freq.begin(), freq.end());
        for(int i = 0; i < freq.size(); i++)
        { 
            int cur = cnt;    
            for(int j = freq.size() - 1; j > i; j--)
            {  
                if(freq[j] - freq[i] <= k) 
                    break;                
                cur += freq[j] - freq[i] - k;
            }
            ans = min(ans, cur);
            cnt += freq[i]; 
        }
        return ans;
    }
};