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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;    
        ListNode *temp;
        
        while (n > 0) {
            n--;
            fast = fast->next;
        }

        if (fast == nullptr) {
            temp = head->next;
            return temp; 
        }
       
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for( int i = 0 ; i < n + 1 ; i ++ ){
            q = q->next;
        }

        while(q){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;


    }
    //    int length =0;
    //    ListNode* cur = head; 
    //    while (cur!= NULL) {
    //        cur = cur->next;
    //        length ++;
    //    }
    //    if (length==1 ) return NULL;
    //    length = length - n -1;
    //    if (length<0) return head->next;
    //    cur = head;
    //    while (length > 0){
    //        cur = cur->next;
    //        length--;
    //    }
    //    ListNode* next = cur->next;
    //    cur->next = next->next;
    //    return head;
    // }
};