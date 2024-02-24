class Solution 
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> vis(n, 0);
        vis[0] = vis[firstPerson] = 1;
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 return a[2] < b[2];
             });
        unordered_map<int, unordered_map<int, int>> adj;
        for(auto &itr : meetings)
        {
            adj[itr[0]][itr[1]] = 0;
            adj[itr[1]][itr[0]] = 0;
        }
        int idx = 0, time = 0, m = meetings.size();
        set<int> st;
        while(idx < m)
        {
            time = meetings[idx][2];
            while(idx < m && meetings[idx][2] == time)
            {
                adj[meetings[idx][0]][meetings[idx][1]] = time;
                adj[meetings[idx][1]][meetings[idx][0]] = time;
                if(vis[meetings[idx][0]])
                    st.insert(meetings[idx][0]);
                if(vis[meetings[idx][1]])
                    st.insert(meetings[idx][1]);
                idx++;
            }
            while(!st.empty())
            {    
                int node = *st.begin();
                st.erase(node);
                vis[node] = 1; 
                for(auto itr : adj[node])
                {
                    if(itr.second == time)
                        st.insert(itr.first), adj[node][itr.first] = -1, adj[itr.first][node] = -1;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};