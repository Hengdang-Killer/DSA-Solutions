class Solution 
{
public:
    int countTriplets(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            
            for (int k = i + 1; k < arr.size(); k++) {
                val ^= arr[k];
                
                if (val == 0) 
                {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};