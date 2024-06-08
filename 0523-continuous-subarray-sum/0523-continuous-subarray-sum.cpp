class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_set<int> st;
        int sum = 0, prevSum;
        for(auto &itr : nums)
        {
            prevSum = sum;
            sum = (sum + itr) % k;
            if(st.find(sum) != st.end())
                return true;
            st.insert(prevSum);
        }
        return false;
    }
};