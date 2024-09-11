class Solution 
{
public:
    int minBitFlips(int &start, int &goal) 
    {
        int xr = start^goal, ans = 0;
        while(xr)
        {
            ans += (xr & 1);
            xr >>= 1;
        }
        return ans;
    }
};