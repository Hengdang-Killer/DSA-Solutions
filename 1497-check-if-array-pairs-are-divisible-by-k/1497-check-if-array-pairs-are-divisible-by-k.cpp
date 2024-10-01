class Solution 
{
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        vector<int> freq(k, 0);
        for(auto &itr : arr)
        {
            if(itr < 0)
            {
                int diff = -itr;
                int q = diff / k;
                itr += (q+1)*k;
            }
            freq[itr%k]++;
        }
        if(freq[0] % 2)
            return false;
        for(int i = 1; i < k; i++)
        {
            int sumReq = k - i;
            if(freq[i] != freq[sumReq])
                return false;
        }
        return true;
    }
};