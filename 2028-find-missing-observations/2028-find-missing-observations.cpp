class Solution 
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = rolls.size();
        int totalSum = mean*(n + m);
        for(int i = 0; i < m; i++)
            totalSum -= rolls[i];
        if(totalSum > 6*n || totalSum < n)
            return {};
        int meanVal = totalSum / n;
        int modVal = totalSum % n;
        vector<int> ans(n, meanVal);
        for(int i = 0; i < modVal; i++)
            ans[i]++;
        return ans;
    }
};