class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int idx = -1, n = nums.size();
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int mx = INT_MAX, idx2 = idx;
        for(int i = idx+1; i < n; i++)
        {
            if(nums[i] > nums[idx] && nums[i] <= mx)
                mx = nums[i], idx2 = i;
        }
        swap(nums[idx], nums[idx2]);
        idx++, idx2 = n-1;
        while(idx < idx2)
            swap(nums[idx++], nums[idx2--]);
        return;
    }
};