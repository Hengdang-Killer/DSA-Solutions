class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> st;
        vector<int> primeFactors = {2, 3, 5};
        pq.push(1);
        st.insert(1);
        long cur = 1;
        for (int i = 0; i < n; i++) 
        {
            cur = pq.top();
            pq.pop();
            for (int prime : primeFactors) 
            {
                long nxt = cur * prime;
                if (st.find(nxt) == st.end()) 
                    pq.push(nxt), st.insert(nxt);
            }
        }
        return (int)cur;     
    }
};