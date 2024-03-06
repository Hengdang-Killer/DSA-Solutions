/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(!head)
            return false;
        ListNode *p, *q;
        p = q = head;
        do
        {
            p = p->next;
            q = q->next;
            q = q ? q->next : q;
        } 
        while(p && q && p != q);
        if(p == q && p)
            return 1;
        return 0;   
    }
};