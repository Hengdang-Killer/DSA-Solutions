class Solution 
{
public:
    int specialArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int x = nums.size() - i;
            if(x <= nums[i])
            {
                if(i == 0)
                    return x;
                else if(x > nums[i-1])
                    return x;
            }
        }
        return -1;
    }
};