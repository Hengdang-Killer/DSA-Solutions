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
private:
    void dfs(TreeNode* root, TreeNode* prev, int par, vector<int>& to_delete, vector<TreeNode*> &ans)
    {
        bool ok = 1;
        int l = 0, r = to_delete.size() - 1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(to_delete[mid] == root->val)
            {
                ok = 0;
                break;
            }
            else if(to_delete[mid] < root->val)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(ok == 1 && par == -1)
            ans.push_back(root);
        if(ok == 0 || par == -1)
        {
            if(prev->right == root)
                prev->right = nullptr;
            if(prev->left == root)
                prev->left = nullptr;
        }
        if(root->left)
        {
            if(ok)
                dfs(root->left, root, root->val, to_delete, ans);
            else
                dfs(root->left, root, -1, to_delete, ans);
        }
        if(root->right)
        {
            if(ok)
                dfs(root->right, root, root->val, to_delete, ans);
            else
                dfs(root->right, root, -1, to_delete, ans);
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        sort(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        TreeNode* cur = root;
        TreeNode head = TreeNode(0, root, nullptr);
        head.left = root;
        dfs(root, &head, -1, to_delete, ans);
        return ans;
    }
};