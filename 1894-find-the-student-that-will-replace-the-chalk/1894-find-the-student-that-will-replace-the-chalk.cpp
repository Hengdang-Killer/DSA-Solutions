class Solution 
{
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
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