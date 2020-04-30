/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**********************************
 双指针法，在fast 和 slow 第一次相遇后，
 将fast重新到head节点，这样下一次相遇的
 时候会在环开始的地方相遇
 ***********************************/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                fast = head;
                while (fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }


        }
        return NULL;
    }
};