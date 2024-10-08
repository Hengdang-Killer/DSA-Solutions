/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(TreeNode *node, ListNode *head)
    {
        if(head == NULL)
            return true;
        if(node == NULL)
            return false;
        if(node->val != head->val)
            return false;
        return dfs(node->left, head->next) || dfs(node->right, head->next);
    }
    bool checkPath(TreeNode *node, ListNode *head)
    {
        if(node == NULL)
            return false;
        if(dfs(node, head))
            return true;
        return checkPath(node->left, head) || checkPath(node->right, head);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(root == NULL)
            return false;
        return checkPath(root, head);
    }
};