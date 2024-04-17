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
    TreeNode* func(TreeNode* root, int val, int depth, int curr) 
    {
        if (!root)
            return NULL;
        if (curr == depth - 1) 
        {
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = leftTemp;
            root->right->right = rightTemp;
            return root;
        }
        root->left = func(root->left, val, depth, curr + 1);
        root->right = func(root->right, val, depth, curr + 1);
        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (depth == 1) 
        {
            TreeNode* head = new TreeNode(val);
            head->left = root;
            return head;
        }
        return func(root, val, depth, 1);
    }
};