class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if(n <= 0)
            return 0;
        int temp = n, cnt = 0;
        while(temp > 0)
        {
            cnt++;
            temp /= 2;
        }
        cnt--;
        return (1<<cnt) == n;
    }
};