class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(1001, 0);
        for(auto itr : arr1)
            freq[itr]++;
        vector<int> ans;
        for(auto itr : arr2)
        {
            while(freq[itr] > 0)
            {
                ans.push_back(itr);
                freq[itr]--;
            }
        }
        for(int i = 0; i <= 1000; i++)
        {
            while(freq[i] > 0)
            {
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};