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
    int dfs(TreeNode* node, bool isLeft) 
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return isLeft ? node->val : 0;
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false); 
        return leftSum + rightSum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return dfs(root, false);
    }
};