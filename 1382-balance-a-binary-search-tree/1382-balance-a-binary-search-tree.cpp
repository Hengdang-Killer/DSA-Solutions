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
    void rightRotation(TreeNode* parent, TreeNode* node)
    {
        TreeNode* tmp = node->left;
        node->left = tmp->right;
        tmp->right = node;
        parent->right = tmp;
    }
    void leftRotate(TreeNode* parent, TreeNode* node) {
        TreeNode* tmp = node->right;
        node->right = tmp->left;
        tmp->left = node;
        parent->right = tmp;
    }

    // Function to perform a series of left rotations to balance the vine
    void makeRotations(TreeNode* vineHead, int count) {
        TreeNode* current = vineHead;
        for (int i = 0; i < count; ++i) {
            TreeNode* tmp = current->right;
            leftRotate(current, tmp);
            current = current->right;
        }
    }
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        if(!root)
                return NULL;
        // Day-Stout-Warren Algorithm
        // Step 1 : Create a skew tree
        TreeNode* head = new TreeNode(0);
        TreeNode *cur = head;
        head->right = root;
        while(cur->right)
        {
            if(cur->right->left)
                rightRotation(cur, cur->right); // to make it perfectly skew
            else
                cur = cur->right;
        }
        
        // Step 2 : Count the nodes
        int nodes = 0;
        cur = head->right;
        while(cur)
            nodes++, cur = cur->right;
        
        int m = pow(2, floor(log2(nodes+1))) - 1;
        makeRotations(head, nodes - m);
        while(m > 1)
            m >>= 1, makeRotations(head, m);
        TreeNode* ans = head->right;
        delete head;
        return ans;
    }
};