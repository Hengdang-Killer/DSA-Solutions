class Solution 
{
public:
    string frequencySort(string s) 
    {
        vector<int> freq1(26, 0), freq2(26, 0), freq3(10, 0);
        for(auto itr : s)
        {
            if(itr >= 'a')
                freq1[itr-'a']++;
            else if(itr >= 'A')
                freq2[itr-'A']++;
            else
                freq3[itr-'0']++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < 26; i++)
        {
            pq.push({freq1[i], i}), pq.push({freq2[i], i});
            if(i < 10)
                pq.push({freq3[i], i});
        }
        string ans = "";
        while(!pq.empty())
        {
            int val = pq.top().first, i = pq.top().second;
            pq.pop();
            if(i < 10 && freq3[i] > freq1[i] && freq3[i] > freq2[i])
            {
                while(val--)
                    ans.push_back('0' + i);
                freq1[i] = 0;
                continue;
            }
            if(freq1[i] > freq2[i] )
            {
                while(val--)
                    ans.push_back('a' + i);
                freq1[i] = 0;
            }
            else
            {
               while(val--)
                    ans.push_back('A' + i);
                freq2[i] = 0;
            }
        }
        return ans;
    }
};