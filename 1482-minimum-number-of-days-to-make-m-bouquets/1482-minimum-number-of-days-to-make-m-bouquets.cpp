class Solution 
{
private:
    bool func(vector<int>& bloomDay, int m, int k, int days)
    {
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= days)
            {
                cnt++;
                if(cnt == k)
                    m--, cnt = 0;
            }
            else
                cnt = 0;
        }
        if(m <= 0)
            return 1;
        return 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        if(((long long)m)*((long long)k) > ((long long)bloomDay.size()))
            return -1;
        int l = 0, r = 1e9, ans = 1e9;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(func(bloomDay, m, k, mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};