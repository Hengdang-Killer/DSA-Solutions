class Solution 
{
private:
    int recursion(int i, int j, map<int, vector<int>> &positions, string &key, string &ring, vector<vector<int>> &dp)
    {
        if (i == key.size()) 
            return 0;
        if (dp[i][j] != -1) 
            return dp[i][j];
        char target = key[i];
        int minSteps = INT_MAX;
        for (int nextPos : positions[target - 'a']) 
        {
            int ok = abs(nextPos - j);
            int steps = ok;
            if(ring.size() - ok < steps)
                steps = ring.size() - ok;
            int totalSteps = steps + recursion(i + 1, nextPos, positions, key, ring, dp);
            minSteps = min(minSteps, totalSteps);
        }
        return dp[i][j] = minSteps + 1;
    }
public:
    int findRotateSteps(string ring, string key) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> dp(key.size(), vector<int>(ring.size()+1, -1));
        map<int, vector<int>> positions;
        for(int i = 0; i < ring.size(); i++)
        {
            positions[ring[i]-'a'].push_back(i);
        }
        return recursion(0, 0, positions, key, ring, dp);
    }
};