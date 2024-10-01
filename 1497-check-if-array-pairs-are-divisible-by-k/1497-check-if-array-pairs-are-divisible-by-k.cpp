class Solution 
{
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> freq(k, 0);
        for(auto &itr : arr)
        {
            if(itr < 0)
                itr += (((-itr) / k)+1)*k;
            freq[itr%k]++;
        }
        if(freq[0] % 2)
            return false;
        for(int i = 1; i < k; i++)
        {
            if(freq[i] != freq[k-i])
                return false;
        }
        return true;
    }
};