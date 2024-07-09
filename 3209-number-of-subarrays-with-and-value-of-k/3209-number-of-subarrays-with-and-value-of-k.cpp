class Solution 
{
public:
    long long countSubarrays(vector<int>& nums, int &k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long ans = 0;
        int n = nums.size();
        vector<vector<int>> v(32, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= 31; j++)
            {
                if(i != 0)
                    v[j][i] += v[j][i-1];
                if(((nums[i] >> j) & 1))
                    v[j][i]++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int l = i, r = n-1, idx = -1;
            while(l <= r)
            {
                int mid = l + (r-l) / 2;
                int len = mid - i + 1;
                int ok = 1;
                for(int j = 0; j <= 31; j++)
                {
                    if(((k>>j)&1) == 0)
                        continue;
                    int cnt = v[j][mid];
                    if(i != 0)
                        cnt -= v[j][i-1];
                    if(cnt != len)
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok)
                    idx = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if(idx != -1)
            {
                int cur = idx;
                l = i, r = idx;
                idx = -1;
                while(l <= r)
                {
                    int mid = l + (r-l) / 2;
                    int len = mid - i + 1, ok = 1;
                    for(int j = 0; j <= 31; j++)
                    {
                        if(((k>>j)&1) == 1)
                            continue;
                        int cnt = v[j][mid];
                        if(i != 0)
                            cnt -= v[j][i-1];
                        if(cnt == len)
                        {
                            ok = 0;
                            break;
                        }   
                    }
                    if(ok)
                        idx = mid, r = mid - 1;
                    else
                        l = mid + 1;
                }
                if(idx != -1)
                {
                    int len = cur - idx + 1;
                    ans += len;
                }
            }
        }
        return ans;
    }
};