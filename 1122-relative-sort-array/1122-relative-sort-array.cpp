class Solution 
{
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
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