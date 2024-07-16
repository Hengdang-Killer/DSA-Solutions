#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

struct segment
{
    int n;
    vector<int> st;
    void initialize(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }
    void build(int start, int end, int node, vector<int> &v)
    {
        if (start == end)
        {
            if(start != 0 && start != n-1 && v[start] > v[start-1] && v[start] > v[start+1])
                st[node] = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = st[2 * node + 1] + st[node * 2 + 2];
    }
    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l and end <= r)
            return st[node];
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, node * 2 + 1);
        int q2 = query(mid + 1, end, l, r, node * 2 + 2);
        return q1 + q2;
    }
    void update(int start, int end, int node, int index, vector<int> &v)
    {
        if (start == end)
        {
            st[node] = 0;
            if(start != 0 && start != n-1 && v[start] > v[start-1] && v[start] > v[start+1])
                st[node] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(start, mid, node * 2 + 1, index, v);
        else
            update(mid + 1, end, node * 2 + 2, index, v);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
        return;
    }
    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int idx, vector<int> &v)
    {
        update(0, n - 1, 0, idx, v);
    }
};



class Solution 
{
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        segment st;
        st.initialize(n);
        st.build(nums);
        vector<int> ans;
        for(auto &itr : queries)
        {
            if(itr[0] == 1)
                ans.push_back(st.query(itr[1]+1, itr[2]-1));
            else
            {
                nums[itr[1]] = itr[2];
                if(itr[1] - 1 >= 0)
                    st.update(itr[1]-1, nums);
                st.update(itr[1], nums);
                if(itr[1] + 1 <= n-1)
                    st.update(itr[1]+1, nums);
            }
        }
        return ans;
    }
};