class Solution 
{
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1])
            {
                pq.push(cnt);
                cnt = 1;
            }
            else
                cnt++;
        }
        pq.push(cnt);
        while(!pq.empty())
        {
            if(k >= pq.top())
            {
                k -= pq.top();
                pq.pop();
            }
            else
                return pq.size();
        }
        return 0;
    }
};