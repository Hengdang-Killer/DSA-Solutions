class Solution 
{
private:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int MOD = 1e9+7;
    int m, n;
    int dp[50][50][51];
    int recursion(int i, int j, int k)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return 1;
        if(k <= 0)
            return 0;
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        long long ans = 0;
        for(auto [a, b] : dir)
        {
            int r = i + a, c = j + b;
            ans = (ans + recursion(r, c, k - 1))%MOD;
        }
        return dp[i][j][k] = ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        this->m = m, this->n = n;
        memset(dp, -1, sizeof(dp));
        return recursion(startRow, startColumn, maxMove);
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();