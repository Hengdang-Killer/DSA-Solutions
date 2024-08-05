class Solution 
{
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string, int> mp;
        for(auto &itr : arr)
            mp[itr]++;
        for(auto &itr : arr)
        {
            if(mp[itr] == 1)
            {
                k--;
                if(k == 0)
                    return itr;
            }
        }
        return "";    
    }
};