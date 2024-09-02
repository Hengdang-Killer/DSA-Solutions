class Solution 
{
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = chalk.size();
        long sum = 0;
        for(auto &itr : chalk)
            sum += itr;
        k -= (k/sum)*sum;
        for(int i = 0; i < n; i++)
        {
            if(k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};