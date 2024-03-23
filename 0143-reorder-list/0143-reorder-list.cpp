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
    void reorderList(ListNode* head) 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (!head) 
            return;
        
        // Tortoise and Hare algorithm
        ListNode *fast = head, *slow = head, *prev = NULL;
        while (fast->next && fast->next->next) 
            fast = fast->next->next, slow = slow->next;
        
        // incrementing position by one if list has even length
        if (fast->next) 
            slow = slow->next;
        
        // Now reverse the second half
        while (slow) 
        {
            fast = slow->next;
            slow->next = prev;
            prev = slow;
            slow = fast;
        }
        slow = prev;
        
        // After reversing the second half, let's merge both the halfes
        while (head && slow) 
        {
            fast = head->next;
            prev = slow->next;
            head->next = slow;
            slow->next = fast;
            head = fast, slow = prev;
        }
        
        // Base case : closing when we had even length arrays
        if (head && head->next) 
            head->next->next = NULL;
    }
};