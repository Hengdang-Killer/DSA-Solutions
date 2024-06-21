class Solution 
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int l = 0, r = 0, sum = 0, ans = 0, n = customers.size();
        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0)
                sum += customers[i];
        }
        while(r < minutes)
        {
            if(grumpy[r] == 1)
                sum += customers[r];
            r++;
        }
        ans = max(ans, sum);
        while(r < n)
        {
            if(grumpy[l] == 1)
                sum -= customers[l];
            if(grumpy[r] == 1)
                sum += customers[r];
            ans = max(ans, sum);
            l++, r++;
        }
        return ans;
    }
};