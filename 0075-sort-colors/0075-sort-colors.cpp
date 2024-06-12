class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int r = nums.size() - 1, l = 0, mid = 0;
        while(mid <= r)
        {
            if(nums[mid] == 0)
                swap(nums[mid++], nums[l++]);
            else if(nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[r--]);
        }   
    }
};