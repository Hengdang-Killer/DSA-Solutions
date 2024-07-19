class Solution 
{
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        int rMax = INT_MIN, cMin = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int rMin = INT_MAX;
            for(int j = 0; j < m; j++)
                rMin = min(rMin, matrix[i][j]);
            rMax = max(rMax, rMin);
        }
        for(int i = 0; i < m; i++)
        {
            int cMax = INT_MIN;
            for(int j = 0; j < n; j++)
                cMax = max(cMax, matrix[j][i]);
            cMin = min(cMax, cMin);
        }
        if(cMin == rMax)
            return {cMin};
        return {};
    }
};