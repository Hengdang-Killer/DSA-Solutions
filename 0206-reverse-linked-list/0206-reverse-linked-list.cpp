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
    ListNode* reverseList(ListNode* head) 
    {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        ListNode* cur = head;
        ListNode* prv = NULL;
        ListNode* tmp = NULL;
        while (cur) 
        {
            tmp = cur -> next;
            cur -> next = prv;
            prv = cur;
            cur = tmp;
        }
        return prv;
    }
};