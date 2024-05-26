class Solution 
{
private:
    int sum;
    void recursion(int i, vector<int> &nums, int ans)
    {
        if(i >= nums.size())
        {
            sum += ans;
            return;
        }
        recursion(i+1, nums, ans);
        recursion(i+1, nums, ans ^ nums[i]);
        return;
    }
public:
    int subsetXORSum(vector<int> &nums) 
    {
        sum = 0;
        recursion(0, nums, 0);
        return sum;
    }
};