/**
 * T.C. using simple arrays = O(5*1e4 * 1e5) = O(5*1e9) - > TLE
 * using bitset -> 1e5 / 64 = 1563
 * so O(5*1e4 * 1563) = O(78 * 1e7) = O(8 * 1e8) -> 1800ms
 * so O(5*1e4 * ((5*1e4) / 64 )) = O(5*1e4 * 781) = O(4 * 1e8) -> 260ms
*/

class Solution 
{
public:
    int maxTotalReward(vector<int>& rewardValues) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = rewardValues.size();
        bitset<100001> dp, validPrev, mask;
        dp[0] = 1;
        sort(rewardValues.begin(), rewardValues.end());
        int cur = 0;
        for(int i = 0; i < n; i++)
        {
            while(cur < rewardValues[i])
                mask[cur++] = 1;
            validPrev = (dp & mask);
            dp |= (validPrev << rewardValues[i]);
        }
        int ans = 100000;
        while(!dp[ans])
            ans--;
        return ans;
    }
};