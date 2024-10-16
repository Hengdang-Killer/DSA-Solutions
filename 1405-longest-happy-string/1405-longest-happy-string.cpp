class Solution 
{
public:
    string longestDiverseString(int a, int b, int c) 
    {
        priority_queue<pair<int, int>> pq;
        if (a > 0) 
            pq.push({a, 0});
        if (b > 0) 
            pq.push({b, 1});
        if (c > 0) 
            pq.push({c, 2});
        string ans = "";
        while (!pq.empty()) 
        {
            pair<int, int> p = pq.top();
            pq.pop();
            if (ans.length() >= 2 && ans[ans.length() - 1] - 'a' == p.second && ans[ans.length() - 2] - 'a' == p.second) 
            {
                if (pq.empty()) 
                    break;
                pair<int, int> temp = pq.top();
                pq.pop();
                ans.push_back('a' + temp.second);
                if (temp.first - 1 > 0) 
                    pq.push({temp.first - 1, temp.second});
            } 
            else 
            {
                p.first--;
                ans.push_back('a' + p.second);
            }
            if (p.first > 0)
                pq.push({p.first, p.second});
        }
        return ans;
    }
};