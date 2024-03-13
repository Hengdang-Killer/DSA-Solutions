class Solution 
{
public:
    int pivotInteger(int n) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l = 1, r = n, total = n*(n+1)/2;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            int sum1 = (mid*(mid+1))/2, sum2 = total - (mid*(mid-1))/2;
            if(sum1 == sum2)
                return mid;
            else if(sum1 < sum2)
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
};