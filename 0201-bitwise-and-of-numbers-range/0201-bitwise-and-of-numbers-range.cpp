class Solution 
{
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(left == 0)
            return 0;
        int bit1 = log2(left), bit2 = log2(right);
        if(bit1 != bit2)
            return 0;
        return (1<<bit1) | rangeBitwiseAnd((left^(1<<bit1)) , (right^(1<<bit1)));
    }
};