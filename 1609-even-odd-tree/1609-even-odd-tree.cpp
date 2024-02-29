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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty())
        {
            int sz = q.size();
            int prev;
            if(level % 2)
                prev = 0;
            else
                prev = 1e9;
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(level % 2 != node->val % 2)
                    return false;
                if(level % 2)
                {
                    if(prev < node->val)
                        prev = node->val;
                    else
                        return false;
                }
                else
                {
                    if(prev > node->val)
                        prev = node->val;
                    else
                        return false;
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
        return true;
    }
};