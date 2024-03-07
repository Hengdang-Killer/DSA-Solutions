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
class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ios_base::sync_with_stdio(0);
        if(!head)
            return head;
        int n = 0;
        ListNode *temp=head;
        while(temp != 0)
            temp = temp->next, n++;
        n = n/2;
        temp = head;
        while(n--)
            temp = temp->next;
        return temp;
    }
};