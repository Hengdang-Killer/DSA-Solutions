class Solution 
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        for(;;)
        {
            for(int i = 0; i < tickets.size(); i++)
            {
                if(tickets[i] == 0)
                    continue;
                tickets[i]--, ans++;
                if(i == k && tickets[i] == 0)
                    return ans;
            }
        }
        return -1;
    }
};