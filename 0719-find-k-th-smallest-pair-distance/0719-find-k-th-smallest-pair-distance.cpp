class Solution 
{
private:
    int check(vector<int>& nums, int maxDistance) 
    {
        int cnt = 0, n = nums.size();
        int l = 0, r = 0;
        while(r < n) 
        {
            while (nums[r] - nums[l] > maxDistance)
                l++;
            cnt += r - l;
            r++;
        }
        return cnt;
    }
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
            int cnt = check(nums, mid);
            if (cnt < k) 
                l = mid + 1;
             else 
                r = mid - 1, ans = mid;
        }
        return ans;
    }
};