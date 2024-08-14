class Solution 
{
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1] - nums[0];
        int ans = r;
        while (l <= r) 
        {
            int mid = l + (r - l) / 2;
            int cnt = 0, left = 0, right = 0;
            while(right < n) 
            {
                while (nums[right] - nums[left] > mid)
                    left++;
                cnt += right - left;
                right++;
            }
            if (cnt < k) 
                l = mid + 1;
             else 
                r = mid - 1, ans = mid;
        }
        return ans;
    }
};