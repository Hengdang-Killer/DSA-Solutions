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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode *head = list1;
        if(a == 0)
            head = list2;
        while(a-1 > 0)
            list1 = list1->next, a--, b--;
        ListNode *temp = list1;
        list1 = list1->next;
        temp->next = list2;
        while(list2->next)
            list2 = list2->next;
        b--;
        while(b--)
            list1 = list1->next;
        list2->next = list1->next;
        return head;
    }
};