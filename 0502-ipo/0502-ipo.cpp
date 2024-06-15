class Solution 
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for(int i = 0; i < n; i++)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int i = 0;
        for(int j = 0; j < k; j++)
        {
            while(i < n && projects[i].first <= w)
                pq.push(projects[i++].second);
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};