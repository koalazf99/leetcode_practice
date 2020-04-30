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
 证明：假设所有节点由a个无环节点+b个环上节点组成
 1)第一次相遇
 fast = slow + n*b
 fast = 2*slow
 --> fast = 2*n*b, slow=n*b
 2)第二次相遇 fast走过的路程从0开始,slow继续，
 但fast和slow每次均只走一步,设走k步后相遇。
 fast = k
 slow = k + n*b;
 此时slow恰好比fast多走n*b,而两者又恰好相遇
 画图易知，两者将恰好在环的节点处完成第二次相遇
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