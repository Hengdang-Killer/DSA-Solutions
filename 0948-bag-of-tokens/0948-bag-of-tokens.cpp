class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int score = 0, ans = 0;
        int l = 0,  r = n - 1;
        while (l <= r) 
        {
            if (power >= tokens[l]) 
            {
                power -= tokens[l];
                score++, l++;
                ans = max(ans, score);
            } 
            else if (score > 0) 
            {
                power += tokens[r];
                score-- , r--;
            } 
            else
                break;
        }
        return ans;
    }
};