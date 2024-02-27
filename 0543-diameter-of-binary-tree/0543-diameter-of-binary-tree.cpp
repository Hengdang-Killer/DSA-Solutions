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
    int recursiveHeight2(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int lh = recursiveHeight2(root->left, diameter);
        int rh = recursiveHeight2(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int diameter = 0;
        recursiveHeight2(root, diameter);
        return diameter;    
    }
};