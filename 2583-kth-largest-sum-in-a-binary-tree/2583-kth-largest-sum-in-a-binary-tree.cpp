/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            long long sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += q.front()->val;
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            if(pq.size() == k)
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
     
            else
                pq.push(sum);
        }    
        if(pq.size() != k)
            return -1;
        return pq.top();    
    }
};