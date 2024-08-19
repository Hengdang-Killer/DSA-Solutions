class Solution 
{
public:
    int minSteps(int n) 
    {
        int ans = 0, val = sqrt(n);
        for(int i = 2; i <= val; i++)
        {
            while(n % i == 0)
                ans += i, n /= i;
        }
        if(n > 1)
            ans += n;
        return ans;
    }
};