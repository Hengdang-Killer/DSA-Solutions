class Solution 
{
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        set<int> st;
        int i = 0, n = nums.size(), ans = 0;
        while(i <= n - k)
        {
            while(!st.empty() && i-*st.begin() >= k)
                st.erase(*st.begin());
            int cnt = st.size();   
            if(cnt % 2)
            {
                if(nums[i] == 1)
                    st.insert(i), ans++;
            }
            else
            {
                if(nums[i] == 0)
                    st.insert(i), ans++;
            }
            i++;
        }
        while(i < n)
        {
            while(!st.empty() && i-*st.begin() >= k)
                st.erase(*st.begin());
            int cnt = st.size();   
            if(cnt % 2)
            {
                if(nums[i] == 1)
                    return -1;
            }
            else
            {
                if(nums[i] == 0)
                    return -1;;
            }
            i++;
        }
        return ans;
    }
};