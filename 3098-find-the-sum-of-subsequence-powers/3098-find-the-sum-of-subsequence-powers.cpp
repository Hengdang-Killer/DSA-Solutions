#pragma GCC optimize("O3", "unroll-loops")
const int mod = 1e9+7;
const int N = 50;
int dp[N+1][N+1][N+1][1230];
set<int> st;
map<int, int> mp1, mp2;

class Solution 
{
private:
    int n, idx;
    int recursion(int i, int prev, int len, int mn, int &k, vector<int> &nums)
    {
        if(len == k)
        {
            if(mn != idx)
                return mp2[mn];
            return 0;
        }
        if(i >= n)
            return 0;
        if(dp[i][prev][len][mn] != -1)
            return dp[i][prev][len][mn];
        int ans = recursion(i+1, prev, len, mn, k, nums);    
        if(len == 0)
            ans += recursion(i+1, i, len+1, idx, k, nums);
        else
        {
            int pv = nums[prev], cv = nums[i], diff = cv - pv;
            if(diff < mp2[mn])
                ans += recursion(i+1, i, len+1, mp1[diff], k, nums);
            else
                    ans += recursion(i+1, i, len+1, mn, k, nums);
        }
        ans %= mod;    
        return dp[i][prev][len][mn] = ans;
    }
public:
    int sumOfPowers(vector<int>& nums, int k) 
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        st.clear(), mp1.clear(), mp2.clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
                st.insert(nums[j] - nums[i]);
        }
        idx = 0;
        for(int x: st)
        {
            mp1[x] = idx;
            mp2[idx++] = x;
        }
        mp1[1e9] = idx;
        mp2[idx] = 1e9;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                for(int jk = 0; jk <= k; jk++)
                    for(int ik = 0; ik <= idx+1; ik++)
                        dp[i][j][jk][ik] = -1;
        return recursion(0, 0, 0, idx, k, nums);
    }
};

auto init = []()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();