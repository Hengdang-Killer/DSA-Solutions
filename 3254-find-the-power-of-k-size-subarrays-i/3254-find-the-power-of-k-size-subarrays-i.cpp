class Solution 
{
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<int> pre(n, 0), ans;
        pre[0] = 1;
        for(int i = 1; i < n; i++)
        {
            pre[i] += pre[i-1];
            if(nums[i] == nums[i-1] + 1)
                pre[i]++;
        }
        if(pre[k-1] == k)
            ans.push_back(nums[k-1]);
        else
            ans.push_back(-1);
        for(int i = k; i < n; i++)
        {
            if(pre[i] - pre[i- k + 1] + 1 == k)
                ans.push_back(nums[i]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};