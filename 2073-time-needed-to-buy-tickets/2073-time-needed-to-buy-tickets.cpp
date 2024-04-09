class Solution 
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for (int i = 0; i < tickets.size(); ++i) 
        {
            if (i <= k) 
                ans += min(tickets[i], tickets[k]);
            else 
                ans += min(tickets[i], tickets[k] - 1);
        }
        return ans;
    }
};